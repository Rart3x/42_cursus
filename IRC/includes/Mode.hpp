/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicarpen <nicarpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:26:42 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/16 09:54:48 by nicarpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Client.hpp"
#include "Utils.hpp"

class Channel;
class Client;
class Server;

class Mode{
	public:
		Mode(void);
		virtual ~Mode();

		void	channelPass(Client *User, Channel *chan, std::string param);
		void	channelPriv(Server *Serv, Client *User, Channel *chan, std::string param);
		void	inviteOnly(Client *User, Channel *chan);
		void	topicRestrict(Client *User, Channel *chan);
		void	userLimit(Client *User, Channel *chan, std::string param);

		bool	isOnModeSet(int c);
		void	callModeFunction(Server *Serv, Client *User, Channel *chan, std::string param, int mode);
};
