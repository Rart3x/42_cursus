/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:20:23 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/02 19:28:24 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	display_frame(t_vars *vars)
{
	const int	speed_animation = 5;

	vars->img.weapon_ptr[vars->on_animation / speed_animation]
		->instances[0].enabled = false;
	vars->on_animation++;
	if (vars->on_animation / speed_animation < 5)
		vars->img.weapon_ptr[vars->on_animation / speed_animation]
			->instances[0].enabled = true;
	else
	{
		vars->img.weapon_ptr[0]->instances[0].enabled = true;
		vars->booleans.minigun_animation = false;
	}
}

void	on_frame_displayed(void *struc)
{
	t_vars	*vars;

	vars = (t_vars *)struc;
	if (vars->booleans.minigun_animation)
		display_frame(vars);
}
