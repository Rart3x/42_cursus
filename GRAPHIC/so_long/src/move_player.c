/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:31:58 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/18 21:55:48 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *struc)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x = find_start_x(struc->map);
	y = find_start_y(struc->map);
	if (struc->map[x - 1][y] != '1')
	{
		if (struc->map[x - 1][y] == 'E' && find_collectible(struc->map) == 0)
			win(struc);
		else if (struc->map[x - 1][y] == 'E'
			&& find_collectible(struc->map) != 0)
			return ;
		struc->map[x - 1][y] = 'P';
		struc->map[x][y] = '0';
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[3].ptr, y * 64, (x - 1) * 64);
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[0].ptr, y * 64, x * 64);
		move_print(struc);
	}
}

void	move_down(t_vars *struc)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x = find_start_x(struc->map);
	y = find_start_y(struc->map);
	if (struc->map[x + 1][y] != '1')
	{
		if (struc->map[x + 1][y] == 'E' && find_collectible(struc->map) == 0)
			win(struc);
		else if (struc->map[x + 1][y] == 'E'
			&& find_collectible(struc->map) != 0)
			return ;
		struc->map[x + 1][y] = 'P';
		struc->map[x][y] = '0';
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[3].ptr, y * 64, (x + 1) * 64);
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[0].ptr, y * 64, x * 64);
		move_print(struc);
	}
}

void	move_left(t_vars *struc)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x = find_start_x(struc->map);
	y = find_start_y(struc->map);
	if (struc->map[x][y - 1] != '1')
	{
		if (struc->map[x][y - 1] == 'E' && find_collectible(struc->map) == 0)
			win(struc);
		else if (struc->map[x][y - 1] == 'E'
			&& find_collectible(struc->map) != 0)
			return ;
		struc->map[x][y - 1] = 'P';
		struc->map[x][y] = '0';
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[3].ptr, (y - 1) * 64, x * 64);
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[0].ptr, y * 64, x * 64);
		move_print(struc);
	}
}

void	move_right(t_vars *struc)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x = find_start_x(struc->map);
	y = find_start_y(struc->map);
	if (struc->map[x][y + 1] != '1')
	{
		if (struc->map[x][y + 1] == 'E' && find_collectible(struc->map) == 0)
			win(struc);
		else if (struc->map[x][y + 1] == 'E'
			&& find_collectible(struc->map) != 0)
			return ;
		struc->map[x][y + 1] = 'P';
		struc->map[x][y] = '0';
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[3].ptr, (y + 1) * 64, x * 64);
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[0].ptr, y * 64, x * 64);
		move_print(struc);
	}
}
