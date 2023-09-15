/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:04:10 by kramjatt          #+#    #+#             */
/*   Updated: 2023/09/06 08:41:41 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Exceptions{

	public :

		/*----------------InvalidExceptions----------------*/
		class	InvalidArgument : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Invalid number of arguments");};
		};

		class	InvalidParameter : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Parameters can't be empty");};
		};

		class	InvalidPort : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Invalid Port");};
		};

		class	InvalidServerPort : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Port value must be integer");};
		};

		class	InvalidCommand : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Invalid command");};
		};

		/*----------------OtherExceptions----------------*/
		class	BindFailed : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Bind failed");};
		};

		class	SocketCreationFailed : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Socket creation failed");};
		};
};
