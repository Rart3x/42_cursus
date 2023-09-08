/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:09:14 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/16 11:20:19 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){

}

int	Contact::fullSpaces(std::string str){

	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != 32)
			return (0);
	}
	return (1);
}

std::string	Contact::initLoop(std::string message)
{
	std::string str = "";

	do {
		std::cout << message << std::endl;
		std::getline(std::cin, str);
		if (str.empty() || fullSpaces(str) == 1) {
			std::cout << "Error: Input can't be empty !" << std::endl;
		}
	} while (str.empty() || fullSpaces(str) == 1);
	return str;
}

void	Contact::init(Contact *contacts, int i){
	
	contacts->index = i;
	contacts->darkestSecret = initLoop("Submit your darkest secret");
	contacts->firstName = initLoop("Submit your first name");
	contacts->lastName = initLoop("Submit your last name");
	contacts->nickname = initLoop("Submit your nickname");
	contacts->phoneNumber = initLoop("Submit your phone number");
}

std::string Contact::cut(std::string str){
	
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::display(Contact contacts){
	
	std::cout << std::setw(10) << contacts.index << std::flush;
	std::cout << "|" << std::setw(10) << cut(contacts.darkestSecret) << std::flush;
	std::cout << "|" << std::setw(10) << cut(contacts.firstName) << std::flush;
	std::cout << "|" << std::setw(10) << cut(contacts.lastName) << std::flush;
	std::cout << "|" << std::setw(10) << cut(contacts.nickname) << std::flush;
	std::cout << "|" << std::setw(10) << cut(contacts.phoneNumber) << std::endl;
}

void	Contact::display_cut(Contact contacts){

	std::cout << std::setw(10) << contacts.index << std::flush;
	std::cout << "|" << std::setw(10) << cut(contacts.firstName) << std::flush;
	std::cout << "|" << std::setw(10) << cut(contacts.lastName) << std::flush;
	std::cout << "|" << std::setw(10) << cut(contacts.nickname) << std::endl;
}

void	Contact::setIndex(int nb){
	this->index = nb;
}
