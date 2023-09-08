/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:42:44 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/17 16:06:56 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	init_weapon(t_vars *struc)
{
	struc->weapons.textures[0] = mlx_load_png("textures/minigun/minigun1.png");
	if (!struc->weapons.textures[0] || struc->weapons.textures[0]->width != 512
		|| struc->weapons.textures[0]->height != 512)
		error_texture_format(struc, "MINIGUN_01");
	struc->weapons.nb_alloc++;
	struc->weapons.textures[1] = mlx_load_png("textures/minigun/minigun2.png");
	if (!struc->weapons.textures[1] || struc->weapons.textures[1]->width != 512
		|| struc->weapons.textures[1]->height != 512)
		error_texture_format(struc, "MINIGUN_02");
	struc->weapons.nb_alloc++;
	struc->weapons.textures[2] = mlx_load_png("textures/minigun/minigun3.png");
	if (!struc->weapons.textures[2] || struc->weapons.textures[2]->width != 512
		|| struc->weapons.textures[2]->height != 512)
		error_texture_format(struc, "MINIGUN_03");
	struc->weapons.nb_alloc++;
	struc->weapons.textures[3] = mlx_load_png("textures/minigun/minigun4.png");
	if (!struc->weapons.textures[3] || struc->weapons.textures[3]->width != 512
		|| struc->weapons.textures[3]->height != 512)
		error_texture_format(struc, "MINIGUN_04");
	struc->weapons.nb_alloc++;
	struc->weapons.textures[4] = mlx_load_png("textures/minigun/minigun5.png");
	if (!struc->weapons.textures[4] || struc->weapons.textures[4]->width != 512
		|| struc->weapons.textures[4]->height != 512)
		error_texture_format(struc, "MINIGUN_05");
	struc->weapons.nb_alloc++;
}

static void	init_button_door(t_vars *struc)
{
	struc->button.nb_alloc = 0;
	struc->button.nb_button = 0;
	struc->button.texture_tab = NULL;
	struc->button.tex_x = 0;
	struc->button.tex_y = 0;
	struc->button.orientation = false;
	struc->button.step_x_column = 0.0;
	struc->button.step_y_column = 0.0;
	struc->button.tex_position_y = 0.0;
	struc->door.nb_alloc = 0;
	struc->door.nb_door = 0;
	struc->door.tex_x = 0;
	struc->door.tex_y = 0;
	struc->door.orientation = false;
	struc->door.step_x_column = 0.0;
	struc->door.step_y_column = 0.0;
	struc->door.tex_position_y = 0.0;
}

static void	init_displ(t_vars *struc)
{
	struc->displ.no_path = NULL;
	struc->displ.so_path = NULL;
	struc->displ.we_path = NULL;
	struc->displ.ea_path = NULL;
	struc->displ.ce_color = NULL;
	struc->displ.fl_color = NULL;
	struc->displ.count_no_path = 0;
	struc->displ.count_so_path = 0;
	struc->displ.count_we_path = 0;
	struc->displ.count_ea_path = 0;
	struc->displ.count_ce_path = 0;
	struc->displ.count_fl_path = 0;
	struc->displ.total = 0;
	struc->wall.textures[0] = NULL;
	struc->wall.textures[1] = NULL;
	struc->wall.textures[2] = NULL;
	struc->wall.textures[3] = NULL;
}

void	init_sub_struct(t_vars *struc)
{
	struc->on_animation = 0;
	struc->mouse.old_x = 0;
	struc->mouse.old_y = 0;
	struc->booleans.button = false;
	struc->booleans.door_animation = false;
	struc->booleans.door_open = false;
	struc->booleans.is_door_text = false;
	struc->booleans.hit_wall = false;
	struc->booleans.map_open = false;
	struc->booleans.minigun_animation = false;
	struc->player.x = 0;
	struc->player.y = 0;
	struc->ray.draw_end = 0;
	struc->ray.draw_start = 0;
	struc->ray.line_height = 0;
	struc->door.nb_alloc = 0;
	struc->wall.nb_alloc = 0;
	struc->weapons.nb_alloc = 0;
	struc->door.texture_tab = NULL;
	struc->wall.texture_tab = NULL;
	init_button_door(struc);
	init_displ(struc);
}
