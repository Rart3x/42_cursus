/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:08:34 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/16 11:08:36 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PHONEBOOK_HPP
# define	PHONEBOOK_HPP

# include	"Contact.hpp"
# include	<sstream>
# include	<stdlib.h>

class PhoneBook{

private:
	Contact		contacts[8];

public:
	PhoneBook(void);
	~PhoneBook(void);
	int			addContact(int choice);
	void		displayContacts(void);
	static void	displayMenu(void);
	void		search(void);
	void		search_solo(void);
	void		menu(void);

};

#endif
