/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:57:59 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/11 18:27:03 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_parsed *a)
{
	if (a->tab[0] > a->tab[1])
		sa(a);
}

void	sort_3(t_parsed *a)
{
	if ((a->tab[2] > a->tab[1] && a->tab[2] > a->tab[0])
		&& a->tab[0] > a->tab[1])
		sa(a);
	if ((a->tab[0] > a->tab[1]) && (a->tab[0] > a->tab[2])
		&& (a->tab[1] > a->tab[2]))
	{
		ra(a);
		sa(a);
	}
	if ((a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2])
		&& a->tab[1] < a->tab[2])
		ra(a);
	if ((a->tab[0] < a->tab[1]) && a->tab[0] > a->tab[2])
		rra(a);
	if ((a->tab[0] < a->tab[1]) && a->tab[1] > a->tab[2])
	{
		rra(a);
		sa(a);
	}
}

void	sort_4(t_parsed *a, t_parsed *b)
{
	while (a->tab[0] != 1)
		ra(a);
	pb(a, b);
	sort_3(a);
	sb(b);
	pa(a, b);
}

void	sort_5(t_parsed *a, t_parsed *b)
{
	while (a->tab[0] != 1)
	{
		if (find_i(a, 1) < a->tab_size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	while (a->tab[0] != 2)
	{
		if (find_i(a, 2) < a->tab_size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	sort_3(a);
	if (b->tab[0] < b->tab[1])
		sb(b);
	pa(a, b);
	pa(a, b);
}
