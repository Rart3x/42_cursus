/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:09:05 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/16 11:16:19 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){

}

PhoneBook::~PhoneBook(void){

}

int PhoneBook::addContact(int choice){
    
	static int i = 0;

    if (choice == 0)
	{
        return (i);
	}

	this->contacts[i % 8].init(&this->contacts[i % 8], i);
	i++;

	std::cout << GREEN << "Contact added !"  << RESET << std::endl;
	return (-1);
}

void	PhoneBook::displayMenu(void){

	std::cout << std::endl;
	std::cout << BLUE <<  "To add a contact, please enter -> ADD" << std::endl;
	std::cout << "To search a contact, please enter -> SEARCH" << std::endl;
	std::cout << "To close your PhoneBook, please enter -> EXIT" << RESET << std::endl;
	std::cout << std::endl;
	return ;
}

void	PhoneBook::menu(void){

	std::string	choice;

	this->displayMenu();
	std::getline(std::cin, choice);
	while (choice.compare("EXIT"))
	{
		if (choice.compare(""))
		{
			if (!choice.compare("ADD"))
				addContact(1);
			else if (!choice.compare("SEARCH"))
				search();
			else
				std::cout << RED << "Invalid command, please retry" << RESET << std::endl;
		}
		std::getline(std::cin, choice);
	}
	exit(EXIT_SUCCESS);
}

void PhoneBook::search()
{
    int i;
    int	j = 0;
	int	k = 0;
	std::string input;

    if (addContact(0) == 0)
    {
        std::cout << RED << "No available contact" << RESET << std::endl;
        return;
    }

    std::cout << GREEN <<  "Contact's list :" << RESET << std::endl;
	while (j < addContact(0))
	{
		if (j < 8)
			this->contacts[j].display_cut(this->contacts[j]);
		j++;
	}

    std::cout << "Enter contact's index : ";

    std::getline (std::cin, input);
	while (input[k])
	{
		if (!std::isdigit(input[k])){
        	std::cout << RED << "Index must be digit\n" << RESET << std::endl;
			return ;
		}
		k++;
	}

	std::istringstream iss (input);
	iss >> i;
    if (std::cin.fail() || i < 0 || i >= addContact(0))
    {
        std::cout << RED << "Invalid index" << RESET << std::endl;
        return;
    }
    this->contacts[i].display(this->contacts[i]);
}
