/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:17:16 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 19:13:01 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(char **map, int fd)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (line_in_file(fd) == ft_strlen(map[i]))
			return (0);
		if (ft_strlen(map[i]) != size)
			return (0);
		i++;
	}
	return (1);
}
