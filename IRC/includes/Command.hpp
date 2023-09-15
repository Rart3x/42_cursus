/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:16:16 by nicarpen          #+#    #+#             */
/*   Updated: 2023/08/14 11:59:41 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*--------Class includes--------*/
#include "Client.hpp"
#include "Mode.hpp"
#include "Utils.hpp"

class Channel;
class Client;
class Server;

class Command : public Mode
{
	public:
		Command();
		virtual ~Command();

		void	invite(Server *Serv, Client *User, std::vector<std::string> strings);
		void	join(Server *Serv, Client *User, std::vector<std::string> strings);
		void	kick(Server *Serv, Client *User, std::vector<std::string> strings);
		void	mode(Server *Serv, Client *User, std::vector<std::string> strings);
		void	msg(Server *Serv, Client *User, std::vector<std::string> strings);
		void	nick(Server *Serv, Client *User, std::vector<std::string> strings);
		void	topic(Server *Serv, Client *User, std::vector<std::string> strings);
		void	user(Server *Serv, Client *User, std::vector<std::string> strings);
};
