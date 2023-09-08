/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:53:38 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/04 21:45:21 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static void	new_images(t_vars *struc)
{
	struc->mlx_ptr = mlx_init(WIDTH, HEIGHT, TITLE, 0);
	struc->img.cross_ptr = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.game_ptr = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.player_ptr = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.ray_ptr = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.weapon_ptr[0] = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.weapon_ptr[1] = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.weapon_ptr[2] = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.weapon_ptr[3] = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
	struc->img.weapon_ptr[4] = mlx_new_image(struc->mlx_ptr, WIDTH, HEIGHT);
}

static void	new_images_to_window(t_vars *struc)
{
	mlx_image_to_window(struc->mlx_ptr, struc->img.game_ptr, 0, 0);
	mlx_image_to_window(struc->mlx_ptr, struc->img.player_ptr, 0, 0);
	mlx_image_to_window(struc->mlx_ptr, struc->img.ray_ptr, 0, 0);
	mlx_image_to_window(struc->mlx_ptr, struc->img.cross_ptr, 0, 0);
	mlx_image_to_window(struc->mlx_ptr, struc->img.weapon_ptr[0],
		(WIDTH / 2) - 256, HEIGHT - 512);
	mlx_image_to_window(struc->mlx_ptr, struc->img.weapon_ptr[1],
		(WIDTH / 2) - 256, HEIGHT - 512);
	mlx_image_to_window(struc->mlx_ptr, struc->img.weapon_ptr[2],
		(WIDTH / 2) - 256, HEIGHT - 512);
	mlx_image_to_window(struc->mlx_ptr, struc->img.weapon_ptr[3],
		(WIDTH / 2) - 256, HEIGHT - 512);
	mlx_image_to_window(struc->mlx_ptr, struc->img.weapon_ptr[4],
		(WIDTH / 2) - 256, HEIGHT - 512);
	struc->img.weapon_ptr[1]->instances[0].enabled = false;
	struc->img.weapon_ptr[2]->instances[0].enabled = false;
	struc->img.weapon_ptr[3]->instances[0].enabled = false;
	struc->img.weapon_ptr[4]->instances[0].enabled = false;
}

static void	textures_to_image(t_vars *struc)
{
	struc->img.weapon_ptr[0] = mlx_texture_to_image(struc->mlx_ptr,
			struc->weapons.textures[0]);
	struc->img.weapon_ptr[1] = mlx_texture_to_image(struc->mlx_ptr,
			struc->weapons.textures[1]);
	struc->img.weapon_ptr[2] = mlx_texture_to_image(struc->mlx_ptr,
			struc->weapons.textures[2]);
	struc->img.weapon_ptr[3] = mlx_texture_to_image(struc->mlx_ptr,
			struc->weapons.textures[3]);
	struc->img.weapon_ptr[4] = mlx_texture_to_image(struc->mlx_ptr,
			struc->weapons.textures[4]);
}

void	display_window(t_vars *struc)
{
	new_images(struc);
	draw_cross(struc);
	textures_to_image(struc);
	new_images_to_window(struc);
	mlx_set_cursor_mode(struc->mlx_ptr, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(struc->mlx_ptr, display_fov, struc);
	mlx_loop_hook(struc->mlx_ptr, on_key_pressed, struc);
	mlx_loop_hook(struc->mlx_ptr, rotate, struc);
	mlx_loop_hook(struc->mlx_ptr, on_click, struc);
	mlx_cursor_hook(struc->mlx_ptr, on_mouse_move, struc);
	mlx_loop_hook(struc->mlx_ptr, on_frame_displayed, struc);
	mlx_loop(struc->mlx_ptr);
}
