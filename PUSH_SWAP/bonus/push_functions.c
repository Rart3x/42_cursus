/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:44:06 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/19 16:04:56 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

void	pa(t_parsed *a, t_parsed *b)
{
	int	i;

	if (b->tab == NULL)
		return ;
	i = a->tab_size;
	while (i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab_size++;
	a->tab[0] = b->tab[0];
	while (i < b->tab_size - 1)
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	b->tab_size--;
}

void	pb(t_parsed *a, t_parsed *b)
{
	int	i;

	if (a->tab == NULL)
		return ;
	i = b->tab_size;
	while (i > 0)
	{
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	b->tab[0] = a->tab[0];
	b->tab_size++;
	i = 0;
	while (i < a->tab_size - 1)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab_size--;
}
