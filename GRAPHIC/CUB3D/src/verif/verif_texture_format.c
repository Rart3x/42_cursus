/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_texture_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:43:51 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/24 00:45:42 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	verif_texture_cub(t_vars *struc)
{
	int	count;
	int	i;

	count = 4;
	i = 0;
	while (i < count)
	{
		if (struc->wall.textures[i]->width != struc->wall.textures[i]->height)
			error_texture_cub(struc, "Texture number : ", i);
		i++;
	}
}

static bool	loop_texture_format(t_vars *struc, char *str, int i)
{
	struc->wall.textures[i] = mlx_load_png(str);
	if (!struc->wall.textures[i])
	{
		i++;
		return (false);
	}
	struc->wall.nb_alloc++;
	i++;
	return (true);
}

bool	verif_texture_format(t_vars *struc)
{
	if (loop_texture_format(struc, struc->displ.no_path, 0) == false)
		error_texture_format(struc, "NORTH_PATH");
	if (loop_texture_format(struc, struc->displ.so_path, 1) == false)
		error_texture_format(struc, "SOUTH_PATH");
	if (loop_texture_format(struc, struc->displ.we_path, 2) == false)
		error_texture_format(struc, "WEST_PATH");
	if (loop_texture_format(struc, struc->displ.ea_path, 3) == false)
		error_texture_format(struc, "EAST_PATH");
	return (true);
}
