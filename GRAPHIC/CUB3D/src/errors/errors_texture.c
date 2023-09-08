/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:41:18 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/16 19:57:14 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	error_missing_textures(t_vars *struc)
{
	ft_printf_fd(2, RED"Error\nnot enough textures\n"RESET);
	free_array2d(struc->file);
	free_textures(struc);
	free(struc);
	exit(EXIT_FAILURE);
}

void	error_texture_cub(t_vars *struc, char *str, int i)
{
	ft_printf_fd(2,
		RED"Error\ntextures have to be perfectly square : %s %d\n"
		RESET, str, i);
	free_in_verif_text_cub(struc);
}

void	error_texture_format(t_vars *struc, char *str)
{
	ft_printf_fd(2,
		RED"Error\nfailed to create *ptr from supposed png file on : %s\n"
		RESET, str);
	free_in_parsing(struc);
}

void	error_rgb(t_vars *struc, char *str)
{
	ft_printf_fd(2, RED"Error\nbad format for RGB : %s\n"
		RESET, str);
	free_in_parsing(struc);
}

void	error_fail_texture(t_vars *struc)
{
	ft_printf_fd(2, RED"Error\nbad format for prefixes [NO, SO, WE, EA, F, C]\n"
		RESET);
	free_in_verif_text_cub(struc);
}
