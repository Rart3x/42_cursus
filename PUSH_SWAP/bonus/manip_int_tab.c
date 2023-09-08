/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_int_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:48:50 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 14:13:28 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*cpy_int_tab(int *tab, int tab_size)
{
	int	*tab_cpy;
	int	i;

	i = 0;
	tab_cpy = ft_calloc(tab_size, sizeof(int));
	while (i < tab_size)
	{
		tab_cpy[i] = tab[i];
		i++;
	}
	return (tab_cpy);
}

int	*normalise_int_tab(t_parsed *a)
{
	int	*a_tab_cpy;
	int	i;
	int	j;
	int	k;

	i = 0;
	a_tab_cpy = cpy_int_tab(a->tab, a->tab_size);
	a_tab_cpy = ft_sort_int_tab(a_tab_cpy, a->tab_size);
	while (i < a->tab_size)
	{
		j = 0;
		k = 1;
		while (j < a->tab_size)
		{
			if (a->tab[i] > a_tab_cpy[j])
				k++;
			j++;
		}
		a->tab[i] = k;
		i++;
	}
	free(a_tab_cpy);
	return (a->tab);
}
