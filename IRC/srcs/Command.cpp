/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicarpen <nicarpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:16:20 by nicarpen          #+#    #+#             */
/*   Updated: 2023/08/21 11:08:55 by nicarpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Channel.hpp"
#include "../includes/Command.hpp"
#include "../includes/Server.hpp"

Command::Command() {}

Command::~Command() {}

static void	inviteError(Client *User, std::string str){

	std::string invite_error_msg = "You failed to invite ";
	invite_error_msg += str + END_MSG;
	std::cout << RED << User->getNickname() << " failed to invite a user" << RESET << std::endl;
	send(User->getSock(), invite_error_msg.c_str(), invite_error_msg.size(), 0);
}

void	Command::invite(Server *Serv, Client *User, std::vector<std::string> strings){

	std::vector<std::string>::iterator it = strings.begin() + 1;

	if (strings.size() == 1)
	{
		inviteError(User, "");
		return ;
	}
	Channel *invitedChannel = Serv->getChannelByName(*it);
	std::string invChan = *it;
	it++;
	if (it == strings.end())
	{
		inviteError(User, "");
		return ;
	}
	Client *invitedClient = Serv->getClientByName(*it);
	std::string invUser = *it;

	if (invitedClient != NULL && invitedChannel != NULL){

		if (strings.size() == 3 && (invChan).compare(0, 1, "#") == 0 && (invChan).size() > 1){
			if (invitedChannel->getUserLimit() == -1 || invitedChannel->getUserLimit() >= invitedChannel->getNbClient() + 1){

				std::string invite_msg = "You succesfully invited to " + invChan + " the user " + invUser + END_MSG;
				std::string invited_msg = "You have been invited in " + invChan + " by the user " + User->getNickname() + END_MSG;

				invitedChannel->clientsChannel.push_back(invitedClient);
				send(User->getSock(), invite_msg.c_str(), invite_msg.size(), 0);
				send(invitedClient->getSock(), invited_msg.c_str(), invited_msg.size(), 0);
				std::cout << YELLOW << User->getNickname() << RESET << " invited " << YELLOW << invUser << RESET <<
				" to " << BLUE << invChan << RESET << std::endl;
			}
			else
				std::cout << RED <<  User->getNickname() << " can't invite in" << RESET << invitedChannel->getName() << RED << " because of user-limit" << RESET << std::endl;
		}
		else
			inviteError(User, (*it));
	}
	else
		inviteError(User, (*it));
}

static void joinSuccess(Server *Serv, Client *User, std::string chanName, bool flag){

	const std::string create_join_msg = "You succesfully created and joined channel " + chanName + END_MSG;;
	const std::string join_msg = "You succesfully joined channel " + chanName + END_MSG ;

	if (flag){
		Serv->addChannel(chanName, User->getSock());
		Channel *chan = Serv->getChannelByName((chanName));
		if (chan != NULL){
			chan->clientsChannel.push_back(User);
			chan->incrementNbClient();
			chan->addAdmin(User->getId());
			std::cout << "Channel " << BLUE << chan->getName() << RESET << " add admin : " << YELLOW << User->getNickname() << RESET << std::endl;
			send(User->getSock(), create_join_msg.c_str(), create_join_msg.size(), 0);
			std::cout << YELLOW << User->getNickname() << RESET << " created and joined channel " << CHANNAME << std::endl;
		}
	}
	else
	{
		Channel *chan = Serv->getChannelByName(chanName);
		chan->clientsChannel.push_back(User);
		chan->incrementNbClient();
		send(User->getSock(), join_msg.c_str(), join_msg.size(), 0);
		std::cout << YELLOW << User->getNickname() << RESET << " joined channel " << CHANNAME << std::endl;
	}
}

void	Command::join(Server *Serv, Client *User, std::vector<std::string> strings){

	if (strings.size() == 1)
	{
		std::cout << RED << User->getNickname() << " failed to JOIN a channel" << RESET << std::endl;
		const std::string error_msg = "Empty Argument for JOIN" + END_MSG;
		send(User->getSock(), error_msg.c_str(), error_msg.size(), 0);
		return ;
	}

	std::vector<std::string>::iterator it = strings.begin() + 1;

	const std::string join_failed_msg = "Channel need to start by '#' and not be empty" + END_MSG;

	if ((*it).compare(0, 1, "#") == 0 && (*it).size() > 1){
		if (Serv->doesChannelExist(*it) == true){
			Channel *chan = Serv->getChannelByName((*it));
			if (chan->getInviteOnly() == false){
				if (chan->getUserLimit() == -1 || chan->getUserLimit() >= chan->getNbClient() + 1){
					if (chan->isClientIsInChannel(User->getNickname()) == false){
						if (strings.size() > 2 && chan->getPass().empty() == 0){
							it++;
							if ((*it).empty() == 0 && chan->getPass() == (*it))
							{
								it--;
								joinSuccess(Serv, User, *it, false);
							}
							else
								std::cout << RED << User->getNickname() << " send incorrect pass " << RESET << CHANNAME << std::endl;
						}
						else if (strings.size() < 3 && chan->getPass().empty() == 0 && chan->getPass() != (*it))
							std::cout << RED <<  User->getNickname() << " send incorrect pass" << RESET << std::endl;
						else
							joinSuccess(Serv, User, *it, false);
					}
					else
						std::cout << RED <<  User->getNickname() << " can't join " << RESET << CHANNAME << " because he's already in" << std::endl;
				}
				else
					std::cout << RED <<  User->getNickname() << " can't join " << RESET << CHANNAME << RED << " because of user-limit" << RESET << std::endl;
			}
			else
				std::cout << RED << User->getNickname() << " can't join " << RESET << CHANNAME << RED << " because of invite-only" << RESET << std::endl;
		}
		else
			joinSuccess(Serv, User, *it, true);
	}
	else
		send(User->getSock(), join_failed_msg.c_str(), join_failed_msg.size(), 0);
}

static void	kickError(Client *User, bool flag){

	if (flag == false){
		std::string no_admin_msg = "You need to be channel's admin to kick clients" + END_MSG;
		send(User->getSock(), no_admin_msg.c_str(), no_admin_msg.size(), 0);
	}
	else if (flag == true){
		std::string bad_kick_msg = "You failed to kick client" + END_MSG;
		send(User->getSock(), bad_kick_msg.c_str(), bad_kick_msg.size(), 0);
	}
}

void	Command::kick(Server *Serv, Client *User, std::vector<std::string> strings){

	if (strings.size() == 1)
	{
		std::cout << RED << User->getNickname() << " failed to KICK a User" << RESET << std::endl;
		const std::string error_msg = "Empty Argument for KICK" + END_MSG;
		send(User->getSock(), error_msg.c_str(), error_msg.size(), 0);
		return ;
	}

	std::vector<std::string>::iterator it = strings.begin() + 1;

	std::string channelName = (*it);
	std::string nameKicked;

	Channel *kickChan = NULL;
	Client	*kickClient = NULL;

	kickChan = Serv->getChannelByName(channelName);

	if (strings.size() > 2){

		it++;

		nameKicked = *it;

		std::string clientKickedName = *it;
		kickClient = Serv->getClientByName(clientKickedName);

		if (kickClient != NULL && kickChan != NULL){
			if (kickChan->isAdmin(User->getId()) == true) {

				std::string kick_msg = "You successfully kicked ";
				kick_msg += kickClient->getNickname();

				std::string kicked_msg = "You have been kicked by ";
				kicked_msg+= User->getNickname();

				kickChan->removeClient(kickClient);
				kickChan->decrementNbClient();

				if (strings.size() > 3){

					it++;

					kick_msg += " for this cause : ";
					kicked_msg += " for this cause : ";

					for (it = strings.begin() + 3; it < strings.end(); it++){
						kick_msg += *it;
						kicked_msg += *it;
						kick_msg += " ";
						kicked_msg += " ";
					}
				}

				kick_msg += END_MSG;
				kicked_msg += END_MSG;

				send(User->getSock(), kick_msg.c_str(), kick_msg.size(), 0);
				send(kickClient->getSock(), kicked_msg.c_str(), kicked_msg.size(), 0);
				std::cout << YELLOW << User->getNickname() << RESET << " has kicked " << YELLOW << nameKicked << RESET << " from channel " << BLUE << channelName << RESET << std::endl;
			}
			else
				kickError(User, false);
		}
		else
			kickError(User, true);
	}
	else
		kickError(User, true);
}

void	Command::mode(Server *Serv, Client *User, std::vector<std::string> strings){

	if (strings.size() == 1)
	{
		std::cout << RED << User->getNickname() << " failed to modify MODE a channel" << RESET << std::endl;
		const std::string error_msg = "Empty Argument for MODE" + END_MSG;
		send(User->getSock(), error_msg.c_str(), error_msg.size(), 0);
		return ;
	}

	std::vector<std::string>::iterator it = strings.begin() + 1;
	std::string modes;
	std::string param = "";

	Channel *chan = Serv->getChannelByName(*it);
	if (strings.size() > 2 && (*it).compare(0, 1, "#") == 0 && (*it).size() > 1){
		it++;
		modes = *it;
		it++;
		if (modes.compare(0, 1, "-") == 0 && modes.size() > 1){
			for(size_t i = 0; i < modes.size(); i++){
				if (isOnModeSet(modes[i]) == true){
					if (it != strings.end())
					{
						param = *it;
						it++;
					}
					else
						param = "";
					callModeFunction(Serv, User, chan, param, modes[i]);
				}
			}
		}
		else
		{
			std::string error_mode_msg = "You failed to change channel's parameter" + END_MSG;
			send(User->getSock(), error_mode_msg.c_str(), error_mode_msg.size(), 0);
		}
	}
	else
	{
		std::string error_mode_msg = "You failed to change channel's parameter" + END_MSG;
		send(User->getSock(), error_mode_msg.c_str(), error_mode_msg.size(), 0);
	}
}

void	Command::msg(Server *Serv, Client *User, std::vector<std::string> strings){

	if (strings.size() > 1){
		std::vector<std::string>::iterator it = strings.begin() + 1;

		if ((*it).compare(0, 1, "#") != 0 && strings.size() > 2){

			int destSocket = Serv->getSockByName(*it);

			it++;

			std::string msg = User->getNickname();
			msg += " send : " + *it + " ";

			if (strings.size() > 2){
				for (it = strings.begin() + 3; it != strings.end(); it++){
					msg += *it;
					msg += " ";
				}
				msg += END_MSG;
			}

			if (destSocket != -1)
			{
				it = strings.begin() + 1;
				std::cout << "Client " << YELLOW << User->getNickname() << RESET << " send message to User " << YELLOW << *it << RESET << std::endl;
				send(destSocket, msg.c_str(), msg.size(), 0);
			}
			else
			{
				std::string badDest = "Bad destination" + END_MSG;
				send(User->getSock(), badDest.c_str(), badDest.size(), 0);
			}
		}
		else if ((*it).compare(0, 1, "#") == 0 && strings.size() > 2){

			Channel *chan = Serv->getChannelByName(*it);
			if (chan == NULL)
			{
				std::cout << YELLOW << (*it) << RESET << RED << " doesn't exist" << RESET << std::endl;
				return ;
			}
			if (chan->isClientIsInChannel(User->getNickname()) == false)
			{
				std::cout << BLUE << User->getNickname() << RESET <<
					RED << " is not available to send messages in " << RESET << YELLOW << chan->getName() << RESET << std::endl;
				return ;
			}

			std::cout << "Client " << YELLOW << User->getId() << RESET << " send message to " << BLUE << *it << RESET << std::endl;

			std::vector<Client *>::iterator iterator;

			std::string msg = User->getNickname();
			msg += " send to channel " + *it + " : ";
			if (strings.size() > 2){
				for (it = strings.begin() + 2; it < strings.end(); it++){
					msg += *it;
					msg += " ";
				}
				msg += END_MSG;
			}
			for (iterator = chan->clientsChannel.begin(); iterator != chan->clientsChannel.end(); iterator++){
				send((*iterator)->getSock(), msg.c_str(), msg.size(), 0);
			}
		}
	}
}

void	Command::nick(Server *Serv, Client *User, std::vector<std::string> strings){

	if (strings.size() == 1)
	{
		std::cout << RED << User->getNickname() << " failed to change nickname" << RESET << std::endl;
		const std::string error_msg = "Empty Argument for NICK" + END_MSG;
		send(User->getSock(), error_msg.c_str(), error_msg.size(), 0);
		return ;
	}
	std::vector<std::string>::iterator it = strings.begin() + 1;

	if ((*it).size() != 0 && Serv->nickIsAlreadyTake(*it) == false){
		std::string nick_msg = "You successfully set your nickname to ";
		nick_msg += (*it) + END_MSG;

		User->setNickname(*it);
		send(User->getSock(), nick_msg.c_str(), nick_msg.size(), 0);
		std::cout << YELLOW << "Client number " << User->getId() << RESET << " set his nickname to " << YELLOW << *it << RESET << std::endl;
	}
	else
	{
		std::string errorMsg = "You failed to set your nickname" + END_MSG;
		send(User->getSock(), errorMsg.c_str(), errorMsg.size(), 0);
		std::cout << RED << User->getNickname() << " failed to set his nickname " << RESET << std::endl;
	}
}

static void	topicError(Client *User, std::string chanName){

	std::string errorMsg = "You failed to display/set";
	errorMsg += chanName + "'s topic" + END_MSG;
	send(User->getSock(), errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << RED << User->getNickname() << " failed to display/set " << chanName << "'s topic" << RESET << std::endl;
}

void	Command::topic(Server *Serv, Client *User, std::vector<std::string> strings){

	std::vector<std::string>::iterator it = strings.begin() + 1;
	std::string channelTopic;

	if (strings.size() == 1)
	{
		std::cout << RED << User->getNickname() << " failed to display/set topic, empty argument" << RESET << std::endl;
		const std::string error_msg = "Empty Argument for TOPIC" + END_MSG;
		send(User->getSock(), error_msg.c_str(), error_msg.size(), 0);
		return ;
	}
	else if (strings.size() == 2){

		std::string topic_msg = *it;

		topic_msg += "'s topic is : ";

		Channel *chan = Serv->getChannelByName(*it);
		if (chan != NULL){
			channelTopic = chan->getTopic();
			if (chan->getTopicRestrict() == false){
				if (channelTopic.empty() == 0){
					topic_msg += chan->getTopic();
					topic_msg += END_MSG;
					send(User->getSock(), topic_msg.c_str(), topic_msg.size(), 0);
				}
				else
				{
					std::string errorMsg = *it;
					errorMsg += "'s topic is not set" + END_MSG;
					send(User->getSock(), errorMsg.c_str(), errorMsg.size(), 0);
				}
			}
			else if (chan->getTopicRestrict() == true && chan->isAdmin(User->getId()) == true){
				channelTopic = chan->getTopic();
				if (channelTopic.empty() == 0){
					topic_msg += chan->getTopic();
					send(User->getSock(), topic_msg.c_str(), topic_msg.size(), 0);
				}
				else
				{
					std::string errorMsg = *it;
					errorMsg += "'s topic is not set" + END_MSG;
					send(User->getSock(), errorMsg.c_str(), errorMsg.size(), 0);
				}
			}
		}
	}
	else if (strings.size() > 2 && (*it).compare(0, 1, "#") == 0){

		Channel *chan = Serv->getChannelByName(*it);

		if (chan != NULL){
			if (chan->getTopicRestrict() == false){
				it++;
				for (it = strings.begin() + 2; it < strings.end(); it++){
					channelTopic += *it;
					channelTopic += " ";
				}
				chan->setTopic((channelTopic));
			}
			else if (chan->getTopicRestrict() == true && chan->isAdmin(User->getId()) == true){
				it++;
				for (it = strings.begin() + 2; it < strings.end(); it++){
					channelTopic += *it;
					channelTopic += " ";
				}
				chan->setTopic((channelTopic));
			}
		}
		else
			topicError(User, (*it));
	}
	else
		topicError(User, (*it));
}

void	Command::user(Server *Serv, Client *User, std::vector<std::string> strings){

	if (strings.size() == 1)
	{
		std::cout << RED << User->getNickname() << " failed to change Username" << RESET << std::endl;
		const std::string error_msg = "Empty Argument for USER" + END_MSG;
		send(User->getSock(), error_msg.c_str(), error_msg.size(), 0);
		return ;
	}

	std::vector<std::string>::iterator it = strings.begin() + 1;

	if ((*it).size() != 0 && Serv->userNameIsAlreadyTake(*it) == false){
		std::string user_msg = "You successfully set your username to ";
		user_msg += (*it) + END_MSG;

		User->setUsername(*it);
		send(User->getSock(), user_msg.c_str(), user_msg.size(), 0);
		std::cout << YELLOW << User->getNickname() << RESET << " set his username to " << YELLOW << *it << RESET << std::endl;
	}
	else
	{
		std::string errorMsg = "You failed to set your username" + END_MSG;
		send(User->getSock(), errorMsg.c_str(), errorMsg.size(), 0);
		std::cout << RED << User->getNickname() << " failed to set his username " << RESET << std::endl;
	}
}

