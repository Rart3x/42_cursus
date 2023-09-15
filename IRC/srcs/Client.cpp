/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:07:16 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/07 19:12:57 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Client.hpp"
#include "../includes/Exceptions.hpp"

/*----------------Constructors/Destructor/Overloads----------------*/
Client::Client(int id){
	std::stringstream ss;
	this->_id = id;
	this->_mainSock = 0;
	this->connected = false;
	ss << id;
	this->_nickname = "User-" + ss.str();
}

Client::Client(int id, int _mainSock){
	this->_id = id;
	this->_mainSock = _mainSock;
	this->connected = true;
	this->_nickname = "[BOT] Nicarpen";
}

Client::~Client(void){
	if (this->_mainSock > 2)
		close(this->_mainSock);
	this->_message.clear();
}

Client& Client::operator=(const Client &rhs){
	if (this != &rhs)
		this->_id = rhs._id;
	return *this;
}

bool	Client::operator==(const Client &rhs){
	if (this->_id == rhs._id && this->_mainSock == rhs._mainSock
		&& this->_nickname == rhs._nickname)
		return true;
	return false;
}

/*----------------Utils----------------*/
bool	Client::isConnected(void) const {
	return (this->connected);
}

std::string Client::ParseEndMessage(char *buffer)
{
	std::string tmp = buffer;
	size_t				len;

	this->_message += tmp;
	len = this->_message.find_first_of(END_MSG);
	if (len == std::string::npos)
	{
		return (this->_message);
	}
	else
	{
		tmp = this->_message;
		this->_message.clear();
		return (tmp);
	}
}

/*----------------Getters----------------*/
int Client::getId(void) const {
	return (this->_id);
}

std::string Client::getNickname(void) const {
	return (this->_nickname);
}

std::string Client::getUsername(void) const {
	return (this->_username);
}

int Client::getSock(void) const {
	return (this->_mainSock);
}

/*----------------Setters----------------*/
void Client::setId(int _id){
	this->_id = _id;
}

void Client::setNickname(std::string _nickname){
	this->_nickname = _nickname.substr(0, _nickname.find('\n'));
}

void Client::setUsername(std::string _username){
	this->_username = _username.substr(0, _username.find('\n'));
}

void Client::setSock(int _mainSock){
	this->_mainSock = _mainSock;
}

void Client::setConnection(bool state){
	this->connected = state;
}
