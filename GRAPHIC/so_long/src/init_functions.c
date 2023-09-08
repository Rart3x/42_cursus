/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:32:25 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/16 19:43:38 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_vars *struc)
{
	struc->width = 64;
	struc->height = 64;
	struc->images[0].ptr = mlx_xpm_file_to_image(struc->mlx,
			"textures/path.xpm", &struc->width, &struc->height);
	struc->images[1].ptr = mlx_xpm_file_to_image(struc->mlx,
			"textures/wall.xpm", &struc->width, &struc->height);
	struc->images[2].ptr = mlx_xpm_file_to_image(struc->mlx,
			"textures/collectible.xpm", &struc->width, &struc->height);
	struc->images[3].ptr = mlx_xpm_file_to_image(struc->mlx,
			"textures/player.xpm", &struc->width, &struc->height);
	struc->images[4].ptr = mlx_xpm_file_to_image(struc->mlx,
			"textures/exit.xpm", &struc->width, &struc->height);
}
