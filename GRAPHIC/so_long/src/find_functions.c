/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:58 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 20:38:16 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_collectible(char **cpy_map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (cpy_map[i])
	{
		j = 0;
		while (cpy_map[i][j])
		{
			if (cpy_map[i][j] == 'C')
				count ++;
			j++;
		}
		i++;
	}
	return (count);
}

int	find_start_x(char **cpy_map)
{
	int	i;
	int	j;

	i = 0;
	while (cpy_map[i])
	{
		j = 0;
		while (cpy_map[i][j])
		{
			if (cpy_map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	find_start_y(char **cpy_map)
{
	int	i;
	int	j;

	i = 0;
	while (cpy_map[i])
	{
		j = 0;
		while (cpy_map[i][j])
		{
			if (cpy_map[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	find_exit(char **cpy_map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (cpy_map[i])
	{
		j = 0;
		while (cpy_map[i][j])
		{
			if (cpy_map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
