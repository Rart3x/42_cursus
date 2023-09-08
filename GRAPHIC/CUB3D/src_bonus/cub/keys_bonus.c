/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:21:19 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/17 13:29:37 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	on_key_pressed(void *struc)
{	
	t_vars		*vars;

	vars = (t_vars *)struc;
	if (mlx_is_key_down(vars->mlx_ptr, MLX_KEY_ESCAPE))
		on_window_closed(struc);
	if (mlx_is_key_down(vars->mlx_ptr, MLX_KEY_W)
		|| mlx_is_key_down(vars->mlx_ptr, MLX_KEY_S)
		|| mlx_is_key_down(vars->mlx_ptr, MLX_KEY_A)
		|| mlx_is_key_down(vars->mlx_ptr, MLX_KEY_D))
		moves(vars);
}
