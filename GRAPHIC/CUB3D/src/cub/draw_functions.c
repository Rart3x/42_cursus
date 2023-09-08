/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:52:03 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/01 11:53:17 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_cross(t_vars *struc)
{
	int	i;
	int	j;

	i = (WIDTH / 2) - 15;
	j = (HEIGHT / 2) - 15;
	while (i <= (WIDTH / 2) + 15)
	{
		mlx_put_pixel(struc->img.cross_ptr, i, (j + 15), RED_C);
		i++;
	}
	i = (WIDTH / 2);
	while (j <= (HEIGHT / 2) + 15)
	{
		mlx_put_pixel(struc->img.cross_ptr, i, j, RED_C);
		j++;
	}
}
