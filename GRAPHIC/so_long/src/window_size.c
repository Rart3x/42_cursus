/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:32:47 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/16 14:32:52 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	window_width(char **map)
{
	int	x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

int	window_height(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
			y++;
		return (y);
		x++;
	}
	return (-1);
}
