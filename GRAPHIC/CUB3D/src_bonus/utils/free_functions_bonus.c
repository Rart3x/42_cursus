/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 06:10:22 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/16 20:05:03 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	free_in_verif_text_cub(t_vars *struc)
{
	int	i;

	i = 0;
	free_array2d(struc->file);
	free_array2d(struc->map);
	while (i < 4 && struc->wall.textures[i])
	{
		mlx_delete_texture(struc->wall.textures[i]);
		i++;
	}
	free_textures(struc);
	free(struc);
	exit(EXIT_FAILURE);
}

void	free_in_parsing(t_vars *struc)
{
	if (struc->file)
		free_array2d(struc->file);
	if (struc->map)
		free_array2d(struc->map);
	free_textures(struc);
	delete_wall(struc);
	free(struc);
	exit(EXIT_FAILURE);
}

void	free_on_fail(t_vars *struc, char *substr, char *substr2, char *substr3)
{
	free(substr);
	free(substr2);
	free(substr3);
	error_fail_texture(struc);
}
