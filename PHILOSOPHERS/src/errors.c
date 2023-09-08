/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:14:27 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/01 17:11:39 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_args(void)
{
	write (2, "Invalid number of arguments\n", 28);
	exit(EXIT_FAILURE);
}

void	error_digit(void)
{
	write (2, "One argument isn't a digit\n", 27);
	exit(EXIT_FAILURE);
}

void	error_overflow(void)
{
	write(2, "Overflow in one or more argument\n", 33);
	exit(EXIT_FAILURE);
}
