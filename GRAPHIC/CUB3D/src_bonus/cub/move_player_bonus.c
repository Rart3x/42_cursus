/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:20:59 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/03 10:07:44 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	moves(t_vars *struc)
{
	if (mlx_is_key_down(struc->mlx_ptr, MLX_KEY_W))
		move_up(struc);
	if (mlx_is_key_down(struc->mlx_ptr, MLX_KEY_S))
		move_down(struc);
	if (struc->orientation == 1)
	{
		if (mlx_is_key_down(struc->mlx_ptr, MLX_KEY_A))
			move_left(struc);
		if (mlx_is_key_down(struc->mlx_ptr, MLX_KEY_D))
			move_right(struc);
	}
	else
	{
		if (mlx_is_key_down(struc->mlx_ptr, MLX_KEY_A))
			move_right(struc);
		if (mlx_is_key_down(struc->mlx_ptr, MLX_KEY_D))
			move_left(struc);
	}
}

void	move_up(t_vars *struc)
{
	const double	move_x = struc->ray.dir_x * MOVE_SPEED;
	const double	move_y = struc->ray.dir_y * MOVE_SPEED;

	if (!is_index_is_walkable(struc, (int)(struc->player.y + (move_y * 2)),
		(int)(struc->player.x)))
		struc->player.y += move_y;
	if (!is_index_is_walkable(struc, (int)(struc->player.y),
		(int)(struc->player.x + (move_x * 2))))
		struc->player.x += move_x;
}		

void	move_down(t_vars *struc)
{
	const double	move_x = struc->ray.dir_x * MOVE_SPEED;
	const double	move_y = struc->ray.dir_y * MOVE_SPEED;

	if (!is_index_is_walkable(struc, (int)(struc->player.y - (move_y * 2)),
		(int)(struc->player.x)))
		struc->player.y -= move_y;
	if (!is_index_is_walkable(struc, (int)(struc->player.y),
		(int)(struc->player.x - (move_x * 2))))
		struc->player.x -= move_x;
}

void	move_left(t_vars *struc)
{
	double	move_x;
	double	move_y;

	move_x = (struc->ray.dir_y * -1) * MOVE_SPEED;
	move_y = (struc->ray.dir_x * MOVE_SPEED);
	if (!is_index_is_walkable(struc, (int)(struc->player.y),
		(int)(struc->player.x - (move_x * 2))))
		struc->player.x -= move_x * struc->orientation;
	if (!is_index_is_walkable(struc, (int)(struc->player.y - (move_y * 2)),
		(int)(struc->player.x)))
		struc->player.y -= move_y * struc->orientation;
}

void	move_right(t_vars *struc)
{
	double	move_x;
	double	move_y;

	move_x = (struc->ray.dir_y * -1) * MOVE_SPEED;
	move_y = (struc->ray.dir_x * MOVE_SPEED);
	if (!is_index_is_walkable(struc, (int)(struc->player.y),
		(int)(struc->player.x + (move_x * 2))))
		struc->player.x += move_x * struc->orientation;
	if (!is_index_is_walkable(struc, (int)(struc->player.y + (move_y * 2)),
		(int)(struc->player.x)))
		struc->player.y += move_y * struc->orientation;
}
