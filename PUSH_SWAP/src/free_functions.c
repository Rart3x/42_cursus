/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:01:34 by kramjatt          #+#    #+#             */
/*   Updated: 2022/12/19 18:46:36 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_structs(t_parsed *a, t_parsed *b)
{
	if (b)
	{
		if (b->tab)
			free(b->tab);
		free(b);
	}
	if (a)
	{
		if (a->tab)
			free(a->tab);
		free(a);
	}
}
