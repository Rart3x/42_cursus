/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:16:50 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/31 06:08:31 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

int	get_longest(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (i < ft_strlen(map[i]))
			i = ft_strlen(map[i]);
		i++;
	}
	return (i);
}

int	get_highest(char **map)
{
	return (count_args2d(map));
}

void	get_center_ray(t_vars *struc, int column, int *x, int *y)
{
	if (column == (WIDTH / 2))
	{
		*x = struc->ray.map_x;
		*y = struc->ray.map_y;
	}
}
