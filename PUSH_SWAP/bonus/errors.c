/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:28:23 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/11 14:53:16 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

void	ft_error(t_parsed *a, t_parsed *b)
{
	write(2, "KO\n", 3);
	free_structs(a, b);
	exit(EXIT_FAILURE);
}

void	ft_error_without_free(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_error_with_return(t_parsed *a, t_parsed *b)
{
	write(2, "OK\n", 3);
	free_structs(a, b);
	exit(EXIT_FAILURE);
}
