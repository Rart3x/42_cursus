/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:47:16 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/17 15:36:07 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_rgb(t_vars *struc, char *substr, char *substr2)
{
	ft_printf_fd(2, RED"Error\nbad format for RGB\n"
		RESET);
	free(substr);
	free(substr2);
	free_in_parsing(struc);
}

void	free_arr_uint(uint32_t **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_textures(t_vars *struc)
{
	if (struc->displ.no_path)
		free(struc->displ.no_path);
	if (struc->displ.so_path)
		free(struc->displ.so_path);
	if (struc->displ.we_path)
		free(struc->displ.we_path);
	if (struc->displ.ea_path)
		free(struc->displ.ea_path);
	if (struc->displ.ce_color)
		free_array2d(struc->displ.ce_color);
	if (struc->displ.fl_color)
		free_array2d(struc->displ.fl_color);
}

void	free_tab_and_textures(t_vars *struc)
{
	int	i;

	i = 0;
	while (i < struc->wall.nb_alloc)
	{
		mlx_delete_texture(struc->wall.textures[i]);
		i++;
	}
}

void	on_window_closed(t_vars *struc)
{
	mlx_delete_image(struc->mlx_ptr, struc->img.game_ptr);
	mlx_delete_image(struc->mlx_ptr, struc->img.player_ptr);
	mlx_delete_image(struc->mlx_ptr, struc->img.ray_ptr);
	free_tab_and_textures(struc);
	mlx_close_window(struc->mlx_ptr);
	mlx_terminate(struc->mlx_ptr);
	free_array2d(struc->file);
	free_array2d(struc->map);
	free_arr_uint(struc->wall.texture_tab);
	free_textures(struc);
	free(struc);
	exit(0);
}
