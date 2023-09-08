/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:17:31 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 20:39:02 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char **map, int fd)
{
	int	i;
	int	j;
	int	count;
	int	line;

	i = 0;
	count = 0;
	line = 0;
	count = line_in_file(fd);
	while (map[i])
	{
		j = 0;
		line = ft_strlen(map[i]) - 1;
		while (map[i][j])
		{
			if (map[i][j] != '\n')
				if (map[i][0] != '1' || map [0][j] != '1'
					|| map[count - 2][j] != '1' || map[i][line - 1] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
