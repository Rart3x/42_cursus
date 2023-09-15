/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:17:42 by nicarpen          #+#    #+#             */
/*   Updated: 2023/09/06 08:45:42 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bot.hpp"
#include "../includes/Server.hpp"
#include "../includes/Exceptions.hpp"

/*----------------Constructors/Destructor----------------*/
Server::Server(){}

Server::Server(int ac, char **av)
{
	g_status = ON;
	this->_NbUsers = 0;
	this->_botSock = -1;

	try
	{
		this->parse_args(ac, av);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		g_status = OFF;
	}

	this->_mainSock = socket(AF_INET, SOCK_STREAM, 0);
	this->_serverInfo.sin_addr.s_addr = inet_addr("127.0.0.1");
	this->_serverInfo.sin_family = AF_INET;
	this->_sockLen = sizeof(_serverInfo);

	try
	{
		if (this->_mainSock == -1)
			throw Exceptions::SocketCreationFailed();

		if (g_status == ON && bind(this->_mainSock, (sockaddr *)&this->_serverInfo, this->_sockLen) == -1)
			throw Exceptions::BindFailed();
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		g_status = OFF;
	}
}

Server::~Server(){

	std::vector<Client *>::iterator it = this->Users.begin();

	if (this->Users.size() > 0){
		while (it != this->Users.end()){
			if (*it){
				delete *it;
			}
			it++;
		}
	}
	std::vector<Channel *>::iterator ite = this->Channels.begin();
	if (this->Channels.size() > 0){
		while (ite != this->Channels.end()){
			if (*ite){
				delete *ite;
			}
			ite++;
		}
	}

	close(_mainSock);
}

/*----------------Utils----------------*/
void	Server::addChannel(std::string _name, int _admin){

	Channel *chan = new Channel();

	chan->addName(_name);
	chan->addAdmin(_admin);
	chan->setID();
	chan->setName(_name);
	chan->setNbClient(0);
	this->Channels.push_back(chan);
}

void	Server::addSocket(int socket){
	this->_sockets.push_back(socket);
}

void	Server::chanEmpty(std::vector<Channel *>::iterator &chan){

	if ((*chan)->getNbClient() == 0)
	{
		std::vector<Channel *>::iterator it;
		for (it = this->Channels.begin(); it != this->Channels.end(); it++)
		{
			if ((*it)->getID() == (*chan)->getID())
			{
				std::cout << "No one in Channel " << BLUE << (*it)->getName() << RESET << ", he is closed" << std::endl;
				delete (*chan);
				it = this->Channels.erase(it);
				break ;
			}
		}
	}
}

void		Server::decrementAllChannels(Client *User){

	std::vector<Channel *>::iterator it_channel = this->Channels.begin();
	std::vector<Client *>::iterator it_client;
	std::vector<Channel *>::iterator tmp;
	bool							state = true;

	while (it_channel != Channels.end()){
		for(it_client = (*it_channel)->clientsChannel.begin(); it_client != (*it_channel)->clientsChannel.end(); ++it_client){
			if (User->getId() == (*it_client)->getId()){
				std::cout << "Client " << YELLOW << (*it_client)->getNickname() << RESET << " quit Channel " << BLUE << (*it_channel)->getName() << RESET << std::endl;
				if ((*it_channel)->isAdmin((*it_client)->getId()) == true)
				{
					(*it_channel)->changeOperator(*it_client);
					(*it_channel)->removeAdmin((*it_client)->getId());
				}
				it_client = (*it_channel)->clientsChannel.erase(it_client);
				(*it_channel)->decrementNbClient();
				this->chanEmpty(it_channel);
				state = false;
				break ;
			}
		}
		if (state == false)
		{
			it_channel = this->Channels.begin();
			state = true;
		}
		else
			it_channel++;
	}
}

bool	Server::doesChannelExist(std::string _name){

	std::vector<Channel*>::iterator it;

	if (this->Channels.size() != 0 && this->Channels.empty() == 0){
		for (it = this->Channels.begin(); it != this->Channels.end(); it++){
			if ((*it)->getName() == _name)
				return (true);
		}
	}
	return (false);
}

void	Server::isCommand(Client *User, std::vector<std::string> strings){

	Channel chan;

	if (strings.empty()) {
		return;
	}

	std::vector<std::string>::iterator it = strings.begin();

	if ((*it).compare("JOIN") == 0)
		chan.join(this, User, strings);
	else if ((*it).compare("INVITE") == 0)
		chan.invite(this, User, strings);
	else if ((*it).compare("KICK") == 0)
		chan.kick(this, User, strings);
	else if ((*it).compare("MODE") == 0)
		chan.mode(this, User, strings);
	else if ((*it).compare("PRIVMSG") == 0)
		chan.msg(this, User, strings);
	else if ((*it).compare("NICK") == 0)
		chan.nick(this, User, strings);
	else if ((*it).compare("TOPIC") == 0)
	 	chan.topic(this, User, strings);
	else if ((*it).compare("USER") == 0)
	 	chan.user(this, User, strings);
	else if ((*it).compare("BOT") == 0){
		if (strings.size() != 1)
		{
			std::string errorMessage = "Invalid argument with BOT command" + END_MSG;
			send(User->getSock(), errorMessage.c_str(), errorMessage.size(), 0);
			std::cout << RED << "Invalid argument with BOT command from " << User->getId() << " : " << *it << RESET << std::endl;

		}
		else if(this->_botSock == -1)
		{
			std::string errorMessage = "BOT is offline, you cannot use it" + END_MSG;
			send(User->getSock(), errorMessage.c_str(), errorMessage.size(), 0);
		}
		else
		{
			std::stringstream ss;
			ss << User->getSock();
			std::string msg;
			ss >> msg;
			send(this->_botSock, msg.c_str(), msg.size(), 0);
		}
	}
	else
	{
		std::string errorMessage = "Invalid command" + END_MSG;
		send(User->getSock(), errorMessage.c_str(), errorMessage.size(), 0);
		std::cout << RED << "Invalid command from " << User->getId() << " : " << *it << RESET << std::endl;
	}
}

int	Server::loopSelect(fd_set &rfds, fd_set &wfds){

	struct timeval tv;
	tv.tv_usec	= 0.0;
	tv.tv_sec	= 1;

	std::vector<Client *>::iterator it;

	FD_ZERO(&rfds);
	FD_ZERO(&wfds);
	FD_SET(this->_mainSock, &rfds);
	FD_SET(this->_mainSock, &wfds);

	for (it = this->Users.begin(); it != this->Users.end(); it++){
		FD_SET((*it)->getSock(), &wfds);
	}

	int retvalue = select(this->getMainSocket() + this->_sockets.size() + 1, &rfds, &wfds, NULL, &tv);
	if (retvalue < 0)
	{
		g_status = OFF;
		return (1);
	}
	else if (retvalue <= 0)
		return (1);
	return (0);
}

void	Server::loopRecv(fd_set &wfds){

	char buffer[BUFFER_SIZE];
	std::vector<Client *>::iterator it;

	for (it = this->Users.begin(); it != this->Users.end(); it++){
		if (FD_ISSET((*it)->getSock(), &wfds))
		{
			if (recv((*it)->getSock(), buffer, BUFFER_SIZE, MSG_PEEK | MSG_DONTWAIT) == 0)
			{
				this->decrementAllChannels(*it);
				if ((*it)->getSock() == this->_botSock)
				{
					std::cout << RED << "Bot has been disconnected." << RESET << std::endl;
					this->_botSock = -1;
				}
				else
					std::cout << RED <<"Client " << (*it)->getId() << " has been disconnected." << RESET << std::endl;
				delete *it;
				it = Users.erase(it);
				this->_NbUsers -= 1;
				break;
			}
			if (recv((*it)->getSock(), buffer, BUFFER_SIZE, 0) > 0){
				if ((*it)->getSock() == this->_botSock){

					std::string str = buffer;
					size_t i = 0;
					while (isdigit(str[i]))
						i++;
					std::string number = str.substr(0, i);
					int socketClient = atoi(number.c_str());

					str = str.substr(i, str.size());
					send(socketClient, str.c_str(), str.length(), 0);
				}
				else
					parseBuffer(buffer, *it);
			}
		}
		memset(buffer, 0, BUFFER_SIZE);
	}
}

bool	Server::nickIsAlreadyTake(std::string str){

	std::vector<Client *>::iterator it;

	for (it = this->Users.begin(); it < this->Users.end(); it++){
		if ((*it)->getNickname().compare(str) == 0)
			return (true);
	}
	return (false);
}

bool	Server::userNameIsAlreadyTake(std::string str){

	std::vector<Client *>::iterator it;

	for (it = this->Users.begin(); it < this->Users.end(); it++){
		if ((*it)->getUsername().compare(str) == 0)
			return (true);
	}
	return (false);
}

void	Server::parseBuffer(char *buffer, Client *User)
{
	std::string	str;
	std::string			tmp;
	size_t				len;

	str = User->ParseEndMessage(buffer);
	len = str.find_first_of(END_MSG);
	if (len == std::string::npos)
	{
		return ;
	}
	while (str.size() >= 2)
	{
		tmp = str.substr(0, len);
		str = str.substr(len + 1, str.size() - len - 1);
		if (User->isConnected() == true)
		{
			isCommand(User, parseMessages(tmp.c_str()));
		}
		else
		{
			try_connect_client(User, tmp.c_str());
		}
		len = str.find_first_of(END_MSG);
	}
}

static bool	are_digit(char *str){

	for (size_t i = 0; i < strlen(str); i++){
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void	Server::parse_args(int ac, char **av)
{
	if (ac != 3)
		throw Exceptions::InvalidArgument();

	if (!strcmp(av[1], "") || !strcmp(av[2], ""))
		throw Exceptions::InvalidParameter();

	if (!are_digit(av[1]))
		throw Exceptions::InvalidServerPort();

	if (std::atoi(av[1]) > 65535 || std::atoi(av[1]) < 0)
		throw Exceptions::InvalidPort();
	
	this->_serverInfo.sin_port = htons(std::atoi(av[1]));
	this->_password = av[2];
}

std::vector<std::string>	Server::parseMessages(const char *str){

	std::istringstream iss(str);
	std::vector<std::string> strings;
	std::vector<std::string>::iterator it;
	std::string buffer;

	while (getline(iss, buffer, ' '))
	{
		buffer = buffer.substr(0, buffer.find('\n'));
		strings.push_back(buffer);
	}
	return (strings);
}

bool	Server::try_connect_client(Client *User, const char *buffer)
{
	std::string buff = buffer;
	if (buff.compare("NICOKENY") == 0){
		this->_botSock = User->getSock();
		User->setConnection(true);
		std::cout << GREEN << "[BOT] is connected" << RESET << std::endl;
		return (true);
	}
	if (buff.size() < 7 || buff.substr(0, 4).compare("PASS") != 0)
	{
		std::string tmp = "Usage : PASS <password>" + END_MSG;
		std::cout << RED << "Error: client number " << User->getId() << " bad input for password" << RESET << std::endl;
		send(User->getSock(), tmp.c_str(), tmp.size(), 0);
		return false;
	}
	const	std::string pass_str = "PASS ";
	std::size_t len = buff.find_first_of("\n\r") - pass_str.size();
	if (buff.substr(pass_str.size(), len).compare(this->_password) == 0)
	{
		std::cout << GREEN << "Client number " << User->getId() << " connected." << RESET << std::endl;
		User->setConnection(true);
		return true;
	}
	else
	{
		std::string tmp = "Bad password" + END_MSG;
		send(User->getSock(), tmp.c_str(), tmp.size(), 0);
		std::cout << RED << "Error: client number " << User->getId() << " bad password : " << buffer << RESET << std::endl;
		return false;
	}
}

/*----------------Getters----------------*/
int			Server::getNewId(){
	if (this->Users.empty() == true)
		return (0);

	std::vector<Client*>::iterator it = this->Users.begin();
	int								i = 0;

	while (it != this->Users.end())
	{
		if (i == (*it)->getId())
		{
			i++;
			it = this->Users.begin();
		}
		else
			it++;
	}
	return (i);
}

Channel*	Server::getChannelByName(std::string _name){

	if (this->Channels.empty() == 0 && _name.empty() == 0){
		std::vector<Channel*>::iterator it;

		for (it = this->Channels.begin(); it != this->Channels.end(); it++){
			if (_name == (*it)->getName()){
				return (*it);
			}
		}
	}
	return (NULL);
}

Client*	Server::getClientByName(std::string _name){

	if (this->Users.empty() == 0 && _name.empty() == 0){
		std::vector<Client*>::iterator it;

		for (it = this->Users.begin(); it != this->Users.end(); it++){
			if (_name == (*it)->getNickname()){
				return (*it);
			}
		}
	}
	return (NULL);
}

Client*	Server::getClientBySocket(char _socket){

	if (this->Users.empty() == 0){
		std::vector<Client*>::iterator it;

		for (it = this->Users.begin(); it != this->Users.end(); it++){
			std::cout << _socket << " : " << (*it)->getSock()  << std::endl;	
			if (_socket == (*it)->getSock()){
				return (*it);
			}
		}
	}
	return (NULL);
}

int		Server::getSockByName(std::string _name){

	std::vector<Client*>::iterator it;

	for (it = this->Users.begin(); it != this->Users.end(); it++){
		if ((*it)->getNickname().compare(_name) == 0)
			return ((*it)->getSock());
	}
	return (-1);
}

int		Server::getMainSocket() const
{
	return (this->_mainSock);
}

sockaddr_in const &Server::getServerInfo() const
{
	return (this->_serverInfo);
}

socklen_t	Server::getSocketLen() const
{
	return (this->_sockLen);
}

int		Server::getNbUsers() const
{
	return (this->_NbUsers);
}

/*----------------Setters----------------*/
void	Server::setMainSocket(int socket)
{
	this->_mainSock = socket;
}

void	Server::setNbUsers(int nb)
{
	this->_NbUsers = nb;
}
