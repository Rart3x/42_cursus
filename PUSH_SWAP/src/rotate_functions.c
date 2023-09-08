/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:27:29 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/19 16:09:30 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_parsed *a)
{
	int	i;
	int	swap;

	swap = a->tab[0];
	i = 0;
	while (i < a->tab_size)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab[i - 1] = swap;
	write(1, "ra\n", 3);
}

void	rb(t_parsed *b)
{
	int	i;
	int	swap;

	swap = b->tab[0];
	i = 0;
	while (i < b->tab_size)
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	b->tab[i - 1] = swap;
	write(1, "rb\n", 3);
}

void	rr(t_parsed *a, t_parsed *b)
{
	ra(a);
	rb(b);
}
