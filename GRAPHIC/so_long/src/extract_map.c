/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:17:38 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 20:28:34 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_in_file(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (line)
		i++;
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

char	**parse_map(char *file)
{
	int		fd;
	int		i;
	int		count;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	i = 0;
	count = line_in_file(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	map = malloc ((sizeof(char *) * count) + 1);
	while (i < (count - 1))
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	check_check(map, fd, file);
	return (map);
}
