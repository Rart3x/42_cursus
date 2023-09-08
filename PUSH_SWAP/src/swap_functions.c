/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:43:55 by kramjatt          #+#    #+#             */
/*   Updated: 2022/12/07 13:43:40 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_parsed *a)
{
	int	swap;

	swap = 0;
	if (a->tab_size < 2)
		return ;
	swap = a->tab[0];
	a->tab[0] = a->tab[1];
	a->tab[1] = swap;
	write(1, "sa\n", 3);
}

void	sb(t_parsed *b)
{
	int	swap;

	swap = 0;
	if (b->tab_size < 2)
		return ;
	swap = b->tab[0];
	b->tab[0] = b->tab[1];
	b->tab[1] = swap;
	write(1, "sb\n", 3);
}

void	ss(t_parsed *a, t_parsed *b)
{
	sa(a);
	sb(b);
}
