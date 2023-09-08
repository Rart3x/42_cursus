/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:17:33 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/16 19:31:35 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_map_if(t_vars *struc, int x, int y)
{
	if (struc->map[x][y] == '0')
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[0].ptr, y * 64, x * 64);
	else if (struc->map[x][y] == '1')
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[1].ptr, y * 64, x * 64);
	else if (struc->map[x][y] == 'C')
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[2].ptr, y * 64, x * 64);
	else if (struc->map[x][y] == 'P')
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[3].ptr, y * 64, x * 64);
	else if (struc->map[x][y] == 'E')
		mlx_put_image_to_window(struc->mlx, struc->win,
			struc->images[4].ptr, y * 64, x * 64);
}

void	display_map(t_vars *struc)
{
	int		x;		
	int		y;

	x = 0;
	while (struc->map[x])
	{
		y = 0;
		while (struc->map[x][y])
		{
			display_map_if(struc, x, y);
			y++;
		}
		x++;
	}
}
