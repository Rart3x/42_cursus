/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:21:19 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/04 21:47:24 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static void	on_click_right(t_vars *vars)
{
	static bool	right_click_pressed = false;

	if (!right_click_pressed
		&& mlx_is_mouse_down(vars->mlx_ptr, MLX_MOUSE_BUTTON_RIGHT)
		&& vars->door.nb_door > 0)
	{
		right_click_pressed = true;
		if (mlx_is_mouse_down(vars->mlx_ptr, MLX_MOUSE_BUTTON_RIGHT)
			&& vars->map[vars->ray.center_y]
			[vars->ray.center_x] == 'B'
			&& vars->map[(int)vars->player.y][(int)vars->player.x] != 'D')
		{
			vars->booleans.door_animation = true;
			if (!vars->booleans.button)
				vars->booleans.button = true;
			else
				vars->booleans.button = false;
		}
	}
	else if (!mlx_is_mouse_down(vars->mlx_ptr, MLX_MOUSE_BUTTON_RIGHT)
		&& vars->door.nb_door > 0)
		right_click_pressed = false;
}

static void	on_click_left(t_vars *vars)
{
	static bool	left_click_pressed = false;

	if (!left_click_pressed
		&& mlx_is_mouse_down(vars->mlx_ptr, MLX_MOUSE_BUTTON_LEFT))
	{
		left_click_pressed = true;
		if (mlx_is_mouse_down(vars->mlx_ptr, MLX_MOUSE_BUTTON_LEFT)
			&& !vars->booleans.minigun_animation)
		{
			vars->booleans.minigun_animation = true;
			vars->on_animation = 0;
		}
	}
	else if (!mlx_is_mouse_down(vars->mlx_ptr, MLX_MOUSE_BUTTON_LEFT))
		left_click_pressed = false;
}

void	on_click(void *struc)
{
	t_vars	*vars;

	vars = (t_vars *)struc;
	on_click_left(vars);
	on_click_right(vars);
}

void	on_mouse_move(double x, double y, void *struc)
{
	t_vars	*vars;

	vars = (t_vars *)struc;
	if ((x > WIDTH - 100 || x < 0 + 100))
		mlx_set_mouse_pos(vars->mlx_ptr, WIDTH / 2, HEIGHT / 2);
	if (vars->orientation == 1)
	{
		if (x - vars->mouse.old_x > 0)
			rotate_right(vars);
		else if (x - vars->mouse.old_x < 0)
			rotate_left(vars);
	}
	else
	{
		if (x - vars->mouse.old_x > 0)
			rotate_left(vars);
		else if (x - vars->mouse.old_x < 0)
			rotate_right(vars);
	}
	vars->mouse.old_x = x;
	vars->mouse.old_y = y;
}
