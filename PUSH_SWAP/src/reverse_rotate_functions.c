/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:01:39 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 17:47:14 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	rrr(t_parsed *a, t_parsed *b)
{
	rra(a);
	rrb(b);
}
