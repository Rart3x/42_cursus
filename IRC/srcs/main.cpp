/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:04:03 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/18 03:23:48 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"
#include "../includes/Exceptions.hpp"

bool g_status = OFF;

static void handle_sigint(int signal)
{
	(void)signal;
	g_status = OFF;
	std::cout << std::endl;
}

static	void	launch_Server(Server &server)
{
	struct timeval tv;
	tv.tv_usec	= 0.0;
	tv.tv_sec	= 2;

	if (select(server.getMainSocket(), NULL, NULL, NULL, &tv) < 0)
	{
		std::cout << RED << "Error : Select main socket" << RESET << std::endl;
		g_status = OFF;
		return ;
	}
	else if (listen(server.getMainSocket(), 1) != 0)
	{
		std::cout << RED << "Error : listening main socket" << RESET << std::endl;
		g_status = OFF;
		return ;
	}
	fcntl(server.getMainSocket(), F_SETFL, O_NONBLOCK);
	std::cout << "-------------------------- SERVER RUNNING ---------------------------" << std::endl;
	std::cout << GREEN << "Waiting for client connection.." << RESET << std::endl;
}

int main(int ac, char **av){

	signal(SIGINT, handle_sigint);

	Server serv(ac, av);

	fd_set	rfds;
	fd_set	wfds;

	int _tmp;

	if (g_status == ON)
	{
		std::cout << "--------------------- SERVER LAUNCH IN PROGRESS ---------------------" << std::endl;
		launch_Server(serv);
	}

	while (g_status == ON){
		try
		{
			int RetValue;
			socklen_t len = serv.getSocketLen();
			FD_ZERO(&rfds);
			FD_ZERO(&wfds);
			FD_SET(serv.getMainSocket(), &rfds);
			FD_SET(serv.getMainSocket(), &wfds);
			RetValue = serv.loopSelect(rfds, wfds);
			if (RetValue == 1)
				continue ;
			_tmp = accept(serv.getMainSocket(), (sockaddr *)&serv.getServerInfo(), &len);
			if (_tmp != -1){
				serv.Users.push_back(new Client(serv.getNewId()));
				serv.Users[serv.getNbUsers()]->setSock(_tmp);
				fcntl(serv.Users[serv.getNbUsers()]->getSock(), F_SETFL, O_NONBLOCK);
				std::cout << GREEN << "Client number " << serv.Users[serv.getNbUsers()]->getId() << " wait for password." << RESET << std::endl;
				serv.addSocket(serv.Users[serv.getNbUsers()]->getSock());
				serv.setNbUsers(serv.getNbUsers() + 1);
			}
			serv.loopRecv(wfds);
		}
		catch (std::exception & e){
			std::cout << RED << e.what() << RESET << std::endl;
		}
		usleep(100);
	}
	std::cout << "--------------------------- SERVER IS OFF ---------------------------" << std::endl;
	return (0);
}
