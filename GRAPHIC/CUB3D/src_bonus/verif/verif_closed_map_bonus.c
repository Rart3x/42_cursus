/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_closed_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:47:55 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/17 19:28:23 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static bool	verif_line_one_last(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != 32 && s[i] != '\n' && s[i] != '\0')
			return (false);
		i++;
	}
	return (true);
}

static bool	is_not_void(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == '0' || c == '1' || c == 'D' || c == 'B')
		return (true);
	return (false);
}

static bool	verif_around(char **map, int i, int j)
{
	if (map[i][j] && (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'D'))
	{
		if (is_not_void(map[i - 1][j]) == false)
			return (false);
		if (is_not_void(map[i + 1][j]) == false)
			return (false);
		if (map[i][j - 1] && is_not_void(map[i][j - 1]) == false)
			return (false);
		if (map[i][j + 1] && is_not_void(map[i][j + 1]) == false)
			return (false);
	}
	return (true);
}

bool	verif_closed_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (i == 0 || i == count_args2d(map) - 1)
		{
			if (verif_line_one_last(map[i]) == false)
				return (false);
		}
		else
		{
			j = 0;
			while (map[i][j])
			{
				if (verif_around(map, i, j) == false)
					return (false);
				j++;
			}
		}
		i++;
	}
	return (true);
}
