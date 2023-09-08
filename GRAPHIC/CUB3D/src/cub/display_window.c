/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:53:38 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/16 17:46:45 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	display_window(t_vars *struc)
{
	struc->mlx_ptr = mlx_init(WIDTH, HEIGHT, TITLE, 0);
	struc->img.cross_ptr = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.game_ptr = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.player_ptr = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.ray_ptr = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	draw_cross(struc);
	mlx_image_to_window(struc->mlx_ptr, struc->img.game_ptr, 0, 0);
	mlx_image_to_window(struc->mlx_ptr, struc->img.player_ptr, 0, 0);
	mlx_image_to_window(struc->mlx_ptr, struc->img.ray_ptr, 0, 0);
	mlx_image_to_window(struc->mlx_ptr, struc->img.cross_ptr, 0, 0);
	mlx_loop_hook(struc->mlx_ptr, display_fov, struc);
	mlx_loop_hook(struc->mlx_ptr, on_key_pressed, struc);
	mlx_loop_hook(struc->mlx_ptr, rotate, struc);
	mlx_loop(struc->mlx_ptr);
}
