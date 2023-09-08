/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:29:47 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/18 19:29:58 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_check(char **map, int fd, char *file)
{
	fd = open(file, O_RDONLY);
	if (check_required(map) == 0)
		error_required(map);
	else if (check_walls(map, fd) == 0)
		error_walls(map);
	else if (check_rectangular(map, fd) == 0)
		error_rect(map);
	else if (check_components(map) == 0)
		error_components(map);
	return ;
}
