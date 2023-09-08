/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:27:46 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 14:16:44 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

int	check_dupli_args(t_parsed *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->tab_size)
	{
		j = i + 1;
		while (j < a->tab_size)
		{
			if (a->tab[i] == a->tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_order(t_parsed *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->tab_size)
	{
		j = i + 1;
		while (j < a->tab_size)
		{
			if (a->tab[i] > a->tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
