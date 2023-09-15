/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:07:56 by kramjatt          #+#    #+#             */
/*   Updated: 2023/09/01 17:46:41 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bot.hpp"

bool g_status = OFF;

static void handle_sigint(int signal)
{
	(void)signal;
	g_status = OFF;
	std::cout << std::endl;
}

int	main(int ac, char **av){

	signal(SIGINT, handle_sigint);

	struct timeval tv;
	tv.tv_usec	= 0.0;
	tv.tv_sec	= 1;

	char buffer[BUFFER_SIZE];

	Bot	bot;

	fd_set	rfds;
	fd_set	wfds;

	try
	{
		bot.parse_args(ac, av);
		bot.connectToServer();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	FD_ZERO(&rfds);
	FD_ZERO(&wfds);
	FD_SET(bot._serverSocket, &rfds);
	FD_SET(bot._serverSocket, &wfds);

	while (g_status == ON)
	{
		try
		{
			FD_ZERO(&rfds);
			FD_SET(bot._serverSocket, &rfds);

			tv.tv_usec = 0;
			tv.tv_sec = 1;

			int selectResult = select(bot._serverSocket + 1, &rfds, NULL, NULL, &tv);
			if (selectResult == -1){
				g_status = OFF;
			}
			else if (selectResult > 0){
				if (FD_ISSET(bot._serverSocket, &rfds)){
					int bytesRead = recv(bot._serverSocket, buffer, BUFFER_SIZE, 0);
					if (bytesRead > 0){
						buffer[bytesRead] = '\0';
						bot.sendDaySinceJanuary(buffer);
					}
				}
			}
		}
		catch (std::exception & e){
			std::cout << RED << e.what() << RESET << std::endl;
		}
		usleep(100);
	}
	close(bot._serverSocket);
	std::cout << "--------------------------- BOT IS OFF ---------------------------" << std::endl;
	return (0);
}
