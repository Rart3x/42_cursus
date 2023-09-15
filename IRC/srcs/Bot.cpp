/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:04:59 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/28 12:31:31 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bot.hpp"
#include "../includes/Server.hpp"

Bot::Bot(void) : Client(0, 0){}

Bot::~Bot(void){}

void Bot::sendDaySinceJanuary(char *buffer){

	std::string str = "[BOT] said : At this moment the number of days that separate us from 1st January is: ";
	std::string hourStr = buffer + str;
	std::time_t now;
	std::tm* timeinfo;

	std::time(&now);
	timeinfo = std::localtime(&now);

	int days = timeinfo->tm_yday;

	std::stringstream ss;
	ss << days;
	hourStr += ss.str() + END_MSG;

	send(this->_serverSocket, hourStr.c_str(), hourStr.size(), 0);
}

void Bot::connectToServer(void){

	std::string _pass = "NICOKENY\r\n";

	this->_serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_serverSocket == -1){
		std::cerr << "Failed to create client socket." << std::endl;
		exit(EXIT_FAILURE);
	}

	this->_serverInfo.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &this->_serverInfo.sin_addr);

	if (connect(this->_serverSocket, (struct sockaddr*)&this->_serverInfo, sizeof(this->_serverInfo)) == -1){
		std::cerr << "Failed to connect to the server." << std::endl;
		close(this->_serverSocket);
		exit(EXIT_FAILURE);
	}
	this->_sockLen = sizeof(_serverInfo);
	std::cout << GREEN << "[BOT] : Connection OK" << RESET << std::endl;
	send(this->_serverSocket, _pass.c_str(), _pass.size(), 0);
	g_status = ON;
}

static bool	are_digit(char *str){

	for (size_t i = 0; i < strlen(str); i++){
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void	Bot::parse_args(int ac, char **av)
{
	if (ac != 2)
		throw Exceptions::InvalidArgument();

	if (!strcmp(av[1], ""))
		throw Exceptions::InvalidParameter();

	if (!are_digit(av[1]))
		throw Exceptions::InvalidServerPort();

	this->_serverInfo.sin_port = htons(std::atoi(av[1]));
}
