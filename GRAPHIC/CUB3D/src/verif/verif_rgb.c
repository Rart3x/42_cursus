/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:20:21 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/03 10:14:55 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	rgb_loop(char **arr)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	if (count_args2d(arr) != 3)
		return (false);
	while (arr[i])
	{
		value = ft_atoi(arr[i]);
		if (value < 0 || value > 255)
			return (false);
		j = 0;
		while (arr[i][j])
		{
			if (!isdigit(arr[i][j]) && arr[i][j] != '\n' && arr[i][j] != '\0')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	verif_rgb(t_vars *struc)
{
	if (rgb_loop(struc->displ.ce_color) == false)
		error_rgb(struc, "CEILLING");
	if (rgb_loop(struc->displ.fl_color) == false)
		error_rgb(struc, "FLOOR");
}
