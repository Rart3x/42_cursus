/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:28:23 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/11 13:44:17 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

void	ft_error(t_parsed *a, t_parsed *b)
{
	write(2, "Error\n", 6);
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
	free_structs(a, b);
	exit(EXIT_FAILURE);
}
