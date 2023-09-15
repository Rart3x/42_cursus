/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:58:54 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/20 04:27:40 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*--------Includes--------*/
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <fcntl.h>
#include <signal.h>
#include <sstream>
#include <stdio.h>
#include <unistd.h>
/*--------Sockets includes--------*/
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

/*-------------Define-------------*/
# define BLUE	"\033[34m"
# define GREEN	"\033[32m"
# define RED	"\033[31m"
# define RESET	"\033[0m"
# define YELLOW	"\033[33m"

# define BUFFER_SIZE 512
# define USERNICKNAME	YELLOW << User->getNickname() << RESET
# define CHANNAME		BLUE << chan->getName() << RESET

# define END_MSG std::string("\r\n")

#define OFF	false
#define ON	true

extern bool g_status;
