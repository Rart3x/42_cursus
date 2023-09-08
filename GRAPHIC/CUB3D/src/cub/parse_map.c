/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:17:38 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/17 14:57:36 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	check_var_filled(t_vars *struc, bool final)
{
	if (struc->displ.no_path && struc->displ.count_no_path < 1)
		struc->displ.count_no_path++;
	if (struc->displ.so_path && struc->displ.count_so_path < 1)
		struc->displ.count_so_path++;
	if (struc->displ.we_path && struc->displ.count_we_path < 1)
		struc->displ.count_we_path++;
	if (struc->displ.ea_path && struc->displ.count_ea_path < 1)
		struc->displ.count_ea_path++;
	if (struc->displ.ce_color && struc->displ.count_ce_path < 1)
		struc->displ.count_ce_path++;
	if (struc->displ.fl_color && struc->displ.count_fl_path < 1)
		struc->displ.count_fl_path++;
	if (final == false && struc->displ.total < 6)
	{
		struc->displ.total = struc->displ.count_no_path
			+ struc->displ.count_so_path
			+ struc->displ.count_we_path + struc->displ.count_ea_path
			+ struc->displ.count_ce_path + struc->displ.count_fl_path;
		return (false);
	}
	if (final == true && struc->displ.total == 0)
		return (true);
	return (true);
}

static int	line_in_file(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (line)
	{
		i++;
		free(line);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
			free(line);
		i++;
	}
	close(fd);
	return (i);
}

char	**parse_file(t_vars *struc, char *file)
{
	int		fd;
	int		i;
	int		count;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(RED"Error\n"RESET);
		free(struc);
		exit(EXIT_FAILURE);
	}
	count = line_in_file(fd);
	if (count == 0)
		error_empty_file(struc);
	close(fd);
	fd = open(file, O_RDONLY);
	map = malloc ((sizeof(char *) * count) + 1);
	i = -1;
	while (++i < (count - 1))
		map[i] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}
