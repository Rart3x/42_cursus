/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:17:35 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 15:46:36 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_window_closed(t_vars *struc)
{
	destroy_img(struc);
	if (struc->win)
		mlx_destroy_window(struc->mlx, struc->win);
	if (struc->mlx)
		mlx_destroy_display(struc->mlx);
	free_tab_tab(struc->map);
	free(struc->mlx);
	exit(0);
}

int	on_key_pressed(int key, t_vars *struc)
{
	if (key == XK_Escape)
		on_window_closed(struc);
	if (key == XK_Up || key == XK_w)
		move_up(struc);
	if (key == XK_Down || key == XK_s)
		move_down(struc);
	if (key == XK_Left || key == XK_a)
		move_left(struc);
	if (key == XK_Right || key == XK_d)
		move_right(struc);
	return (0);
}

void	display_window(t_vars *struc)
{
	struc->win = mlx_new_window(struc->mlx, window_height
			(struc->map) * 64, window_width(struc->map) * 64, "Keny the game");
	mlx_hook(struc->win, 2, 1L << 0, on_key_pressed, struc);
	mlx_hook(struc->win, 17, 1L << 17, on_window_closed, struc);
	display_map(struc);
	mlx_loop(struc->mlx);
}
