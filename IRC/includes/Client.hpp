/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:07:30 by kramjatt          #+#    #+#             */
/*   Updated: 2023/09/06 08:46:13 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*--------Class includes--------*/
#include "Utils.hpp"
#include <sstream>

class Client{
	public:
	/*--------Constructors/Destructor--------*/
		Client(int _id);
		Client(int id, int _mainSock);
		virtual ~Client(void);
	/*--------Overloads--------*/
		Client& operator=(const Client &rhs);
		bool	operator==(const Client &rhs);
	/*--------Utils--------*/
		bool isConnected(void) const;
		std::string ParseEndMessage(char *buffer);
	/*--------Getters--------*/
		int getId(void) const;
		int getSock(void) const;
		std::string getNickname(void) const;
		std::string getUsername(void) const;

	/*--------Setters--------*/
		void setId(int _id);
		void setNickname(std::string _nickname);
		void setUsername(std::string _username);
		void setSock(int _mainSock);
		void setConnection(bool state);

	protected:
		int _id;
		int _mainSock;

		std::string _nickname;
		std::string _username;
		bool		connected;
		std::string	_message;

};
