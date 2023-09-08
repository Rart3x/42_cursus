/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:43:55 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 19:41:42 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

void	sa(t_parsed *a)
{
	int	swap;

	swap = 0;
	if (a->tab_size < 2)
		return ;
	swap = a->tab[0];
	a->tab[0] = a->tab[1];
	a->tab[1] = swap;
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
}

void	ss(t_parsed *a, t_parsed *b)
{
	sa(a);
	sb(b);
}
