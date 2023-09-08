/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:55:32 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/02 17:37:48 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	rotate_right(t_vars *struc)
{
	double	old_dir_y;
	double	old_plane_y;
	double	rotation;

	rotation = ROTATE * (PI / 180.0);
	old_dir_y = struc->ray.dir_y;
	rotation *= struc->orientation;
	struc->ray.dir_y = struc->ray.dir_y * cosf(-rotation)
		- struc->ray.dir_x * sinf(-rotation);
	struc->ray.dir_x = old_dir_y * sinf(-rotation)
		+ struc->ray.dir_x * cosf(-rotation);
	old_plane_y = struc->ray.plane_y;
	struc->ray.plane_y = struc->ray.plane_y * cosf(-rotation)
		- struc->ray.plane_x * sinf(-rotation);
	struc->ray.plane_x = old_plane_y * sinf(-rotation)
		+ struc->ray.plane_x * cosf(-rotation);
}

void	rotate_left(t_vars *struc)
{
	double	old_dir_y;
	double	old_plane_y;
	double	rotation;

	rotation = ROTATE * (PI / 180.0);
	old_dir_y = struc->ray.dir_y;
	rotation *= struc->orientation;
	struc->ray.dir_y = struc->ray.dir_y * cosf(rotation)
		- struc->ray.dir_x * sinf(rotation);
	struc->ray.dir_x = old_dir_y * sinf(rotation)
		+ struc->ray.dir_x * cosf(rotation);
	old_plane_y = struc->ray.plane_y;
	struc->ray.plane_y = struc->ray.plane_y * cosf(rotation)
		- struc->ray.plane_x * sinf(rotation);
	struc->ray.plane_x = old_plane_y * sinf(rotation)
		+ struc->ray.plane_x * cosf(rotation);
}

void	rotate(void *struc)
{
	t_vars	*vars;

	vars = (t_vars *)struc;
	if (vars->orientation == 1)
	{
		if (mlx_is_key_down(vars->mlx_ptr, MLX_KEY_LEFT))
			rotate_left(vars);
		if (mlx_is_key_down(vars->mlx_ptr, MLX_KEY_RIGHT))
			rotate_right(vars);
	}
	else
	{
		if (mlx_is_key_down(vars->mlx_ptr, MLX_KEY_LEFT))
			rotate_right(vars);
		if (mlx_is_key_down(vars->mlx_ptr, MLX_KEY_RIGHT))
			rotate_left(vars);
	}
	(void)struc;
}
