/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:01:39 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 19:42:06 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

void	rra(t_parsed *a)
{
	int	i;
	int	swap;

	swap = a->tab[a->tab_size - 1];
	i = a->tab_size - 1;
	while (i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab[0] = swap;
}

void	rrb(t_parsed *b)
{
	int	i;
	int	swap;

	swap = b->tab[b->tab_size - 1];
	i = b->tab_size - 1;
	while (i > 0)
	{
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	b->tab[0] = swap;
}

void	rrr(t_parsed *a, t_parsed *b)
{
	rra(a);
	rrb(b);
}
