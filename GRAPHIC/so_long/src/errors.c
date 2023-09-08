/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:19:26 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/27 22:18:25 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit_start(char **map, int exit_map, int start_pos)
{
	if (exit_map > 1 || start_pos > 1)
		write (2, "Error, map should have only one exit and start !\n", 49);
	if (exit_map < 1 || start_pos < 1)
		write (2, "Error, map should have one exit and start !\n", 44);
	free_tab_tab(map);
	exit(EXIT_FAILURE);
}

void	error_rect(char **map)
{
	write (2, "Error, map should be a rectangle !\n", 35);
	free_tab_tab(map);
	exit(EXIT_FAILURE);
}

void	error_required(char **map)
{
	write (2,
		"Error, map need at least 1 collectible, starting position and exit !\n",
		69);
	free_tab_tab(map);
	exit(EXIT_FAILURE);
}

void	error_walls(char **map)
{
	write (2, "Error, map need to be surround by walls !\n", 42);
	free_tab_tab(map);
	exit(EXIT_FAILURE);
}

void	error_components(char **map)
{
	write (2,
		"Error, map elements must be a '0', '1', 'C', 'E', or 'P' !\n",
		59);
	free_tab_tab(map);
	exit(EXIT_FAILURE);
}
