/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicarpen <nicarpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:29:24 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/16 11:21:57 by nicarpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Mode.hpp"
#include "../includes/Channel.hpp"
#include "../includes/Command.hpp"
#include "../includes/Server.hpp"

/*--------------------------------------------Constructor/Destructor--------------------------------------------*/
Mode::Mode(void){}

Mode::~Mode(void){}

/*--------------------------------------------Mode--------------------------------------------*/
void	Mode::channelPass(Client *User, Channel *chan, std::string param){

	if (chan != NULL && chan->isAdmin(User->getId()) == true){
		if (param.size() > 0)
		{
			if (chan->getPass().empty() == true)
				chan->setPass(param);
			std::cout << USERNICKNAME << " set " << CHANNAME << " password" << RESET << std::endl;
		}
		else
			chan->clearPass();
	}
	else
		std::cout << USERNICKNAME << RED << " can't change channel password" << RESET << std::endl;
}

void	Mode::channelPriv(Server *Serv, Client *User, Channel *chan, std::string param){

	if (chan != NULL && chan->isAdmin(User->getId()) == true){
		Client *newAdmin = Serv->getClientByName(param);
		if (newAdmin != NULL && chan->isAdmin(newAdmin->getId()) == false){
			chan->addAdmin(newAdmin->getId());
			std::cout << USERNICKNAME << " set operator privilege's " << BLUE << newAdmin->getNickname() << RESET
				<< " for " << CHANNAME << std::endl;
		}
		else if (chan->isAdmin(newAdmin->getId()) == true){
			chan->removeAdmin(newAdmin->getId());
			std::cout << USERNICKNAME << " delete operator privilege's " << BLUE << newAdmin->getNickname() << RESET
				<< " for " << CHANNAME << std::endl;
		}
		else
			std::cout << USERNICKNAME << RED << " failed to channel privilege" << RESET << std::endl;
	}
	else
		std::cout << USERNICKNAME << RED << " can't channel privilege" << RESET << std::endl;
}

void	Mode::inviteOnly(Client *User, Channel *chan){

	if (chan != NULL && chan->isAdmin(User->getId()) == true){
		if (chan->getInviteOnly() == false)
		{
			chan->setInviteOnly(true);
			std::cout << USERNICKNAME << " set " << CHANNAME << " on invite-only" << RESET << std::endl;
		}
		else
		{
			chan->setInviteOnly(false);
			std::cout << USERNICKNAME << " remove " << CHANNAME << " on invite-only" << RESET << std::endl;
		}
	}
	else
		std::cout << USERNICKNAME << RED << " can't change invite-only mode" << RESET << std::endl;
}

void	Mode::topicRestrict(Client *User, Channel *chan){

	if (chan != NULL && chan->isAdmin(User->getId()) == true){
		if (chan->getTopicRestrict() == true)
			chan->setTopicRestrict(false);
		else
			chan->setTopicRestrict(true);
		std::cout << USERNICKNAME << " set " << CHANNAME << " topic restrict" << RESET << std::endl;
	}
	else
		std::cout << USERNICKNAME << RED << " can't set topic restrict" << RESET << std::endl;
}

void	Mode::userLimit(Client *User, Channel *chan, std::string param){

	if (chan != NULL && chan->isAdmin(User->getId()) == true ){
		std::istringstream iss(param);
		int userLimit;
		iss >> userLimit;
		if (userLimit < 0 || userLimit < chan->getNbClient()){
			std::cout << USERNICKNAME << RED << " set an incorrect user-limit" << RESET << std::endl;
		}
		else
		{
			if (chan->getUserLimit() == -1)
				chan->setUserLimit(userLimit);
			else
				chan->setUserLimit(-1);
			std::cout << USERNICKNAME << " set " << CHANNAME << " user limit" << RESET << std::endl;
		}
	}
	else
		std::cout << USERNICKNAME << RED << " can't change user-limit" << RESET << std::endl;
}

/*-------------------------------------------Utils--------------------------------------------*/

void	Mode::callModeFunction(Server *Serv, Client *User, Channel *chan, std::string param, int mode){

	if (mode == 'i')
	{
		inviteOnly(User, chan);
		return ;
	}
	else if (mode == 't')
	{
		topicRestrict(User, chan);
		return ;
	}
	else if (mode == 'k')
	{
		channelPass(User,chan, param);
		return ;
	}
	if (param.size() != 0)
	{
		if (mode == 'o')
			channelPriv(Serv, User, chan, param);
		else if (mode == 'l')
			userLimit(User, chan, param);
	}
	else
	{
		std::string error_mode_msg = "You must specify parameter for mode ";
		error_mode_msg.push_back(mode);
		error_mode_msg += END_MSG;
		send(User->getSock(), error_mode_msg.c_str(), error_mode_msg.size(), 0);
	}
}

bool	Mode::isOnModeSet(int c){
	if (c == 'i' || c == 't' || c == 'k' || c == 'o' || c == 'l')
		return (true);
	return (false);
}
