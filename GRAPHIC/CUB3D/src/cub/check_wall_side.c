/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_side.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 05:28:00 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/31 05:30:16 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	check_wall_side_part(t_vars *struc)
{
	if (struc->ray.side == 1 && struc->ray.step_y == -1)
	{
		struc->wall.orientation = true;
		return (0);
	}
	else if (struc->ray.side == 1 && struc->ray.step_y == 1)
	{
		struc->wall.orientation = false;
		return (1);
	}
	else if (struc->ray.side == 0 && struc->ray.step_x == -1)
	{
		struc->wall.orientation = false;
		return (2);
	}
	else if (struc->ray.side == 0 && struc->ray.step_x == 1)
	{
		struc->wall.orientation = true;
		return (3);
	}
	return (-1);
}

int	check_wall_side(t_vars *struc)
{
	int	ret;

	ret = check_wall_side_part(struc);
	if (ret == 0 || ret == 1 || ret == 2 || ret == 3)
		return (ret);
	return (-1);
}
