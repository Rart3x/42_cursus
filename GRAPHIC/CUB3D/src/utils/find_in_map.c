/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:20:53 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/02 17:19:16 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static double	player_orientation(t_vars *struc, char **map)
{
	struc->player.x = find_in_map_x(map, 'N') + 0.5;
	struc->player.y = find_in_map_y(map, 'N') + 0.5;
	if (struc->player.x != -0.5 && struc->player.y != -0.5)
		return (0);
	struc->player.x = find_in_map_x(map, 'S') + 0.5;
	struc->player.y = find_in_map_y(map, 'S') + 0.5;
	if (struc->player.x != -0.5 && struc->player.y != -0.5)
		return (1);
	struc->player.x = find_in_map_x(map, 'W') + 0.5;
	struc->player.y = find_in_map_y(map, 'W') + 0.5;
	if (struc->player.x != -0.5 && struc->player.y != -0.5)
		return (2);
	struc->player.x = find_in_map_x(map, 'E') + 0.5;
	struc->player.y = find_in_map_y(map, 'E') + 0.5;
	if (struc->player.x != -0.5 && struc->player.y != -0.5)
		return (3);
	return (4);
}

static void	find_player_part(t_vars *struc)
{
	if (player_orientation(struc, struc->map) == 2)
	{
		struc->ray.dir_x = -1.0;
		struc->ray.dir_y = 0.0;
		struc->ray.plane_x = 0;
		struc->ray.plane_y = (FOV_A / 100);
		struc->orientation = 1;
	}
	else if (player_orientation(struc, struc->map) == 3)
	{
		struc->ray.dir_x = 1.0;
		struc->ray.dir_y = 0.0;
		struc->ray.plane_x = 0;
		struc->ray.plane_y = (FOV_A / 100) * -1;
		struc->orientation = 1;
	}
}

void	find_player(t_vars *struc)
{
	if (player_orientation(struc, struc->map) == 0)
	{
		struc->ray.dir_x = 0.0;
		struc->ray.dir_y = -1.0;
		struc->ray.plane_x = (FOV_A / 100) * -1;
		struc->ray.plane_y = 0;
		struc->orientation = 1;
	}
	else if (player_orientation(struc, struc->map) == 1)
	{
		struc->ray.dir_x = 0.0;
		struc->ray.dir_y = 1.0;
		struc->ray.plane_x = (FOV_A / 100);
		struc->ray.plane_y = 0;
		struc->orientation = 1;
	}
	else if (player_orientation(struc, struc->map) > 1)
		find_player_part(struc);
}

int	find_in_map_y(char **map, int c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	find_in_map_x(char **map, int c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}
