/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:17:20 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 19:21:14 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	search_in_components(char c)
{
	const char	*components = "01CEP";
	int			i;

	i = 0;
	while (components[i])
	{
		if (components[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_components(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '\n')
				if (search_in_components(map[i][j]) == 0)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
