/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_required.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:17:27 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/19 17:35:30 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_required_player(char **map, int start_pos)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				start_pos += 1;
			j++;
		}
		i++;
	}
	return (start_pos);
}

int	check_required(char **map)
{
	int	exit;
	int	collectible;
	int	start_pos;

	exit = 0;
	collectible = 0;
	start_pos = 0;
	exit = find_exit(map);
	collectible = find_collectible(map);
	start_pos = is_required_player(map, start_pos);
	if (exit == 1 && collectible >= 1 && start_pos == 1)
		return (1);
	if ((exit != 1 || start_pos != 1))
		error_exit_start(map, exit, start_pos);
	return (0);
}
