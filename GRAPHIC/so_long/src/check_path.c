/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:17:23 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/18 22:17:27 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_around(char **map, int x, int y);

static void	check_around_x(char **map, int x, int y)
{
	if (map[x][y + 1] != '1' && map[x][y + 1] != 'K')
	{
		if (map[x][y + 1] == 'E')
		{
			map[x][y + 1] = '1';
			return ;
		}
		map[x][y + 1] = 'K';
		check_around(map, x, y + 1);
	}
	if (map[x][y - 1] != '1' && map[x][y - 1] != 'K')
	{
		if (map[x][y - 1] == 'E')
		{
			map[x][y - 1] = '1';
			return ;
		}
		map[x][y - 1] = 'K';
		check_around(map, x, y - 1);
	}
}

static void	check_around_y(char **map, int x, int y)
{
	if (map[x + 1][y] != '1' && map[x + 1][y] != 'K')
	{
		if (map[x + 1][y] == 'E')
		{
			map[x + 1][y] = '1';
			return ;
		}
		map[x + 1][y] = 'K';
		check_around(map, x + 1, y);
	}
	if (map[x - 1][y] != '1' && map[x - 1][y] != 'K')
	{
		if (map[x - 1][y] == 'E')
		{
			map[x - 1][y] = '1';
			return ;
		}
		map[x - 1][y] = 'K';
		check_around(map, x - 1, y);
	}
}

static void	check_around(char **map, int x, int y)
{
	check_around_x(map, x, y);
	check_around_y(map, x, y);
}

int	check_path(char **map)
{
	char	**cpy_map;
	int		start_x;
	int		start_y;

	start_x = 0;
	start_y = 0;
	cpy_map = copy_tab_tab(map);
	start_x = find_start_x(cpy_map);
	start_y = find_start_y(cpy_map);
	check_around(cpy_map, start_x, start_y);
	if (find_collectible(cpy_map) == 0 && find_exit(cpy_map) == 0)
	{	
		free_tab_tab(cpy_map);
		return (1);
	}
	if (cpy_map)
		free_tab_tab(cpy_map);
	return (0);
}
