/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:17:54 by nicarpen          #+#    #+#             */
/*   Updated: 2023/08/28 12:56:59 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*--------Class includes--------*/
#include "Bot.hpp"
#include "Channel.hpp"
#include "Utils.hpp"

class Bot;

class Server
{
	public:
		Server(int ac, char **av);
		~Server();

		void	addSocket(int socket);
		void	addChannel(std::string _name, int _admin);
		void	chanEmpty(std::vector<Channel *>::iterator &chan);
		void	decrementAllChannels(Client *User);
		bool	doesChannelExist(std::string name);
		int		loopSelect(fd_set& rfds, fd_set& wfds);
		void	loopRecv(fd_set &wfds);
		bool	nickIsAlreadyTake(std::string str);
		bool	userNameIsAlreadyTake(std::string str);

		void 	isCommand(Client *User, std::vector<std::string> strings);

		std::vector<std::string>	parseMessages(const char *str);
		void						parseBuffer(char *buffer, Client *User);
		bool						try_connect_client(Client *User, const char *buffer);

	/*----------------Getters----------------*/
		Channel*			getChannelByName(std::string _name);
		Client*				getClientBySocket(char c);
		Client*				getClientByName(std::string _name);
		int					getSockByName(std::string _name);
		int					getMainSocket() const;
		sockaddr_in	const	&getServerInfo() const;
		socklen_t			getSocketLen() const;
		int					getNbUsers() const;
		int					getNewId();

	/*----------------Setters----------------*/
		void		setMainSocket(int socket);
		void		setNbUsers(int nb);

	/*----------------Vectors----------------*/
		std::vector<Client*>	Users;
		std::vector<Channel*>	Channels;

	private:
		Server();

		int					_botSock;
		int					_mainSock;
		std::vector<int> 	_sockets;

		socklen_t			_sockLen;
		sockaddr_in			_serverInfo;

		std::string			_password;

		void				parse_args(int ac, char **argv);
		size_t				_NbUsers;
};
