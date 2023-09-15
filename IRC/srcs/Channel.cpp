 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicarpen <nicarpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:03:54 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/08 13:20:33 by nicarpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Channel.hpp"
#include "../includes/Exceptions.hpp"

/*----------------Constructors/Destructor----------------*/
Channel::Channel(void){
	this->_inviteOnly = false;
	this->_topicRestrict = false;
	this->_id = -1;
	this->_pass = "";
	this->_nbClient = -1;
	this->_topic = "";
	this->_userLimit= -1;
	this->_pass = "";
}

Channel::~Channel(void){}

/*----------------Utils----------------*/
void	Channel::addName(std::string name){
	this->_names.push_back(name);
}

bool	Channel::isClientIsInChannel(std::string _name){

	std::vector<Client *>::iterator it;

	for (it = this->clientsChannel.begin(); it < this->clientsChannel.end(); it++){
		if ((*it)->getNickname() == _name){
			return (true);
		}
	}
	return (false);
}

void	Channel::clearPass(void){
	this->_pass.clear();
}

void	Channel::decrementNbClient(void){
	this->_nbClient--;
}

void	Channel::incrementNbClient(void){
	this->_nbClient++;
}

void	Channel::removeClient(Client* User){

	std::vector<Client *>::iterator it;

	int	clientId;

	for (it = this->clientsChannel.begin(); it < this->clientsChannel.end(); it++){
		if ((User == (*it)) == true){
			clientId = (*it)->getId();
			removeAdmin(clientId);
			clientsChannel.erase(it);
		}
	}
}

void	Channel::changeOperator(Client *User)
{
	std::vector<Client *>::iterator it;

	for(it = this->clientsChannel.begin(); it != this->clientsChannel.end(); it++)
	{
		if (User->getId() != (*it)->getId() && this->clientsChannel.size() >= 2)
		{
			std::cout << YELLOW << User->getNickname() << RESET << " no longer operator in channel " << BLUE << this->getName() << RESET \
			<< " now operator is " << YELLOW << (*it)->getNickname() << RESET << std::endl;
			this->addAdmin((*it)->getId());
			return ;
		}
	}
}

void	Channel::addAdmin(const int id)
{
	this->_admin.push_back(id);
}

void	Channel::removeAdmin(const int id)
{
	std::vector<int>::iterator it;

	for (it = this->_admin.begin(); it != this->_admin.end(); it++)
	{
		if (*it == id)
		{
			this->_admin.erase(it);
			return ;
		}
	}
}

bool	Channel::isAdmin(const int id)
{
	std::vector<int>::iterator it;

	for (it = this->_admin.begin(); it != this->_admin.end(); it++)
	{
		if (*it == id)
		{
			return true;
		}
	}
	return false;
}

/*----------------Getters----------------*/
bool	Channel::getInviteOnly(void) const {
	return (this->_inviteOnly);
}

bool	Channel::getTopicRestrict(void) const {
	return (this->_topicRestrict);
}

int Channel::getID(void) const{
	return(this->_id);
}

int	Channel::getNbClient(void) const{
	return (this->_nbClient);
}

int	Channel::getUserLimit(void) const{
	return (this->_userLimit);
}

std::string Channel::getName(void) const{
	return(this->_name);
}

std::string Channel::getPass(void) const{
	return(this->_pass);
}

std::string Channel::getTopic(void) const{
	return (this->_topic);
}

std::vector<std::string> Channel::getNames(void) const{
	return(this->_names);
}

/*----------------Setters----------------*/
void	Channel::setInviteOnly(bool _inviteOnly){
	this->_inviteOnly = _inviteOnly;
}

void	Channel::setTopicRestrict(bool _topicRestrict){
	this->_topicRestrict = _topicRestrict;
}

void Channel::setNbClient(int _nbClient){
	this->_nbClient = _nbClient;
}

void Channel::setUserLimit(int _userLimit){
	this->_userLimit = _userLimit;
}

void Channel::setID(void){
	static int i = 0;

	this->_id = i;
	i++;
}

void Channel::setName(const std::string _name){
	this->_name = _name;
}

void Channel::setPass(const std::string _pass){
	this->_pass = _pass;
}

void	Channel::setTopic(const std::string _topic){
	this->_topic = _topic;
}
