/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:07:22 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/28 11:38:03 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Client.hpp"
#include "Exceptions.hpp"
#include "Server.hpp"
#include "Utils.hpp"

class Client;
class Server;

class Bot : public Client 
{
    public :
        Bot(void);
        ~Bot();

        void    sendDaySinceJanuary(char *buffer);

        void    connectToServer(void);
        void    parse_args(int ac, char **av);

        int  _serverSocket;
    
        socklen_t			_sockLen;
		sockaddr_in			_serverInfo;
};