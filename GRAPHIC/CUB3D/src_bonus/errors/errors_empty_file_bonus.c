/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_empty_file_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:41:18 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/05 14:28:12 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	error_empty_file(t_vars *struc)
{
	ft_printf_fd(2, RED"Error\nfile is empty\n"RESET);
	free(struc);
	exit(EXIT_FAILURE);
}

void	error_empty_line_map(t_vars *struc)
{
	ft_printf_fd(2, RED"Error\nmap is false\n"RESET);
	free_textures(struc);
	free_array2d(struc->file);
	free(struc);
	exit(EXIT_FAILURE);
}
