/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:55:37 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/03 10:15:53 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static void	anti_fisheye(t_vars *vars)
{
	if (vars->ray.side == 0)
		vars->ray.perp_wall_dist = (vars->ray.side_dist_x
				- vars->ray.delta_dist_x);
	else
		vars->ray.perp_wall_dist = (vars->ray.side_dist_y
				- vars->ray.delta_dist_y);
	if (vars->ray.perp_wall_dist != 0)
		vars->ray.line_height = ((double)HEIGHT / (vars->ray.perp_wall_dist))
			* 0.625;
	vars->ray.draw_start = ((vars->ray.line_height * -1) / 2 + HEIGHT / 2);
	vars->ray.draw_end = (vars->ray.line_height / 2 + HEIGHT / 2);
}

static void	one_ray(t_vars *vars, int x)
{
	while (!vars->booleans.hit_wall)
	{
		if (vars->ray.side_dist_x < vars->ray.side_dist_y)
		{
			vars->ray.side_dist_x += vars->ray.delta_dist_x;
			vars->ray.map_x += vars->ray.step_x;
			vars->ray.side = 0;
		}
		else
		{
			vars->ray.side_dist_y += vars->ray.delta_dist_y;
			vars->ray.map_y += vars->ray.step_y;
			vars->ray.side = 1;
		}
		if (vars->map[vars->ray.map_y][vars->ray.map_x] == 'D'
			&& vars->booleans.door_open && x == (WIDTH / 2))
			get_center_ray(vars, x, &vars->ray.door_x, &vars->ray.door_y);
		if ((vars->map[vars->ray.map_y][vars->ray.map_x] == '1'
			|| vars->map[vars->ray.map_y][vars->ray.map_x] == 'B'
			|| (vars->map[vars->ray.map_y][vars->ray.map_x] == 'D'
			&& !vars->booleans.door_open)))
			vars->booleans.hit_wall = true;
	}
}

static void	deltas(t_vars *vars)
{
	if (vars->ray.raydir_x == 0)
		vars->ray.delta_dist_x = 1e30;
	else
		vars->ray.delta_dist_x = fabs(1 / vars->ray.raydir_x);
	if (vars->ray.raydir_y == 0)
		vars->ray.delta_dist_y = 1e30;
	else
		vars->ray.delta_dist_y = fabs(1 / vars->ray.raydir_y);
	vars->booleans.hit_wall = false;
}

static void	steps(t_vars *vars)
{
	if (vars->ray.raydir_x < 0)
	{
		vars->ray.step_x = -1;
		vars->ray.side_dist_x = (vars->player.x - vars->ray.map_x)
			* vars->ray.delta_dist_x;
	}
	else
	{
		vars->ray.step_x = 1;
		vars->ray.side_dist_x = (vars->ray.map_x + 1.0 - vars->player.x)
			* vars->ray.delta_dist_x;
	}
	if (vars->ray.raydir_y < 0)
	{
		vars->ray.step_y = -1;
		vars->ray.side_dist_y = (vars->player.y - vars->ray.map_y)
			* vars->ray.delta_dist_y;
	}
	else
	{
		vars->ray.step_y = 1;
		vars->ray.side_dist_y = (vars->ray.map_y + 1.0 - vars->player.y)
			* vars->ray.delta_dist_y;
	}
}

void	display_fov(void *struc)
{
	t_vars	*vars;
	int		x;

	vars = (t_vars *)struc;
	x = WIDTH;
	vars->ray.delta_dist_x = 0.0;
	vars->ray.delta_dist_y = 0.0;
	while (x >= 0)
	{
		vars->ray.camera_x = (2 * x) / (double)WIDTH - 1;
		vars->ray.raydir_x = vars->ray.dir_x - vars->ray.plane_x
			* vars->ray.camera_x;
		vars->ray.raydir_y = vars->ray.dir_y - vars->ray.plane_y
			* vars->ray.camera_x;
		vars->ray.map_x = (int)floor(vars->player.x);
		vars->ray.map_y = (int)floor(vars->player.y);
		steps(vars);
		deltas(vars);
		one_ray(vars, x);
		anti_fisheye(vars);
		get_center_ray(vars, x, &vars->ray.center_x, &vars->ray.center_y);
		draw_column(vars, x, (vars->ray.draw_end - vars->ray.draw_start));
		x--;
	}
	tempo_texture(vars);
}
