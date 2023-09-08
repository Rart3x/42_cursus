/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:08:43 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/16 11:15:51 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

# define BLUE	 "\033[34m"
# define GREEN   "\033[32m"
# define RED     "\033[31m"
# define RESET   "\033[0m"

class Contact {

private:
    int			index;
	std::string darkestSecret;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string	phoneNumber;

public:
	Contact();
	std::string	cut(std::string str);
	void		display(Contact contacts);
	void		display_cut(Contact contacts);
	int			fullSpaces(std::string str);
	void		init(Contact *contacts, int i);
	std::string	initLoop(std::string message);
	void		setIndex(int nb);
};

#endif
