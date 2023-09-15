/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:04:17 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/14 15:53:58 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*--------Class includes--------*/
#include "Command.hpp"
#include "Utils.hpp"

class Channel : public Command
{
	public:
		Channel(void);
		~Channel(void);

	/*----------------Utils----------------*/
		void	addName(std::string _name);
		bool	isClientIsInChannel(std::string _name);
		void	decrementNbClient(void);
		void	incrementNbClient(void);
		void	removeClient(Client *User);
		void	changeOperator(Client *User);
		void	addAdmin(const int id);
		void	removeAdmin(const int id);
		bool	isAdmin(const int id);
	/*----------------Getters----------------*/

		bool					getInviteOnly(void) const;
		bool					getTopicRestrict(void) const;

		std::vector<int>		getadminId(void) const;
		int						getID(void) const;
		int						getNbClient(void) const;
		int						getUserLimit(void) const;

		std::string getName(void) const;
		std::string getPass(void) const;
		std::string getTopic(void) const;

		std::vector<std::string> getNames(void) const;
	/*----------------Setters----------------*/
		void	setInviteOnly(bool _inviteOnly);
		void	setTopicRestrict(bool _topicRestrict);

		void	setID(void);
		void	setNbClient(const int _nbClient);
		void	setUserLimit(int userLimit);

		void	setName(const std::string _name);
		void	setPass(const std::string _pass);
		void	setTopic(const std::string _topic);

		void	clearPass(void);

		std::vector<Client*> clientsChannel;

	private:
		bool _inviteOnly;
		bool _topicRestrict;

		int _id;
		int	_nbClient;
		int	_userLimit;

		std::string	_name;
		std::string	_pass;
		std::string _topic;

		std::vector<int> _admin;
		std::vector<std::string> _names;
};
