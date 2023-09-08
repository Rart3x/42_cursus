/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:47:34 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/05 18:35:13 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	error_nbr_args(void)
{
	ft_printf_fd(2, RED"Error\nneedonly 1 argument\n"RESET);
	exit(EXIT_FAILURE);
}

void	error_extension(void)
{
	ft_printf_fd(2, RED"Error\nmap extension's not .cub\n"RESET);
	exit(EXIT_FAILURE);
}

void	error_component(t_vars *struc)
{
	ft_printf_fd(2,
		RED"Error\nmap components have to be [0, 1, N, S, W, E, B, D]\n"
		RESET);
	free_in_parsing(struc);
	exit(EXIT_FAILURE);
}

void	error_player_pos(t_vars *struc)
{
	ft_printf_fd(2, RED
		"Error\nmap must contain at least and max one player position\n"RESET);
	free_in_parsing(struc);
	exit(EXIT_FAILURE);
}

void	error_closed_map(t_vars *struc)
{
	ft_printf_fd(2, RED
		"Error\nmap must me be surrounded by walls [1]\n"RESET);
	free_in_parsing(struc);
	exit(EXIT_FAILURE);
}
