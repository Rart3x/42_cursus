/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:14:06 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/17 17:14:07 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	check_color_floor(t_vars *struc, char *substr,
	char *substr2, char *str)
{
	int	i;

	i = -1;
	if ((str[struc->index + 1] != ' ' && str[struc->index + 1] != '\t'))
		return (false);
	if (check_commas_format(substr2))
		struc->displ.fl_color = ft_split(substr2, ',');
	else
	{
		free(substr);
		free(substr2);
		error_rgb(struc, "FLOOR");
	}
	while (++i < 3)
	{
		if (!struc->displ.fl_color[i]
			|| only_spaces(struc->displ.fl_color[i]) == true)
			free_rgb(struc, substr, substr2);
		struc->displ.fl_color[i] = ft_strtrim(struc->displ.fl_color[i],
				"\n \t", 1);
		if (!verif_ceil_floor(struc->displ.fl_color, substr, substr2))
			error_rgb(struc, "FLOOR");
		struc->displ.floor[i] = ft_atoi(struc->displ.fl_color[i]);
	}
	return (true);
}

bool	check_color_ceil(t_vars *struc, char *substr,
	char *substr2, char *str)
{
	int	i;

	i = -1;
	if ((str[struc->index + 1] != ' ' && str[struc->index + 1] != '\t'))
		return (false);
	if (check_commas_format(substr2))
		struc->displ.ce_color = ft_split(substr2, ',');
	else
	{
		free(substr);
		free(substr2);
		error_rgb(struc, "CEILLING");
	}
	while (++i < 3)
	{
		if (!struc->displ.ce_color[i]
			|| only_spaces(struc->displ.ce_color[i]) == true)
			free_rgb(struc, substr, substr2);
		struc->displ.ce_color[i] = ft_strtrim(struc->displ.ce_color[i],
				"\n \t", 1);
		if (!verif_ceil_floor(struc->displ.ce_color, substr, substr2))
			error_rgb(struc, "CEILLING");
		struc->displ.ceilling[i] = ft_atoi(struc->displ.ce_color[i]);
	}
	return (true);
}

static bool	check_textures_part_we(t_vars *struc, char *substr,
	char *substr2, char *str)
{
	if (!ft_strncmp(substr, "WE", 2) && struc->displ.count_we_path < 1)
	{
		if ((str[struc->index + 2] != ' ' && str[struc->index + 2] != '\t'))
			return (false);
		struc->displ.we_path = ft_strtrim(substr2, "\n \t", 0);
		struc->flag_texture = true;
	}
	else if (!ft_strncmp(substr, "EA", 2) && struc->displ.count_ea_path < 1)
	{		
		if ((str[struc->index + 2] != ' ' && str[struc->index + 2] != '\t'))
			return (false);
		struc->displ.ea_path = ft_strtrim(substr2, "\n \t", 0);
		struc->flag_texture = true;
	}
	return (true);
}

static bool	check_textures_part_ns(t_vars *struc, char *substr,
	char *substr2, char *str)
{
	if (!ft_strncmp(substr, "NO", 2) && struc->displ.count_no_path < 1)
	{		
		if ((str[struc->index + 2] != ' ' && str[struc->index + 2] != '\t'))
			return (false);
		struc->displ.no_path = ft_strtrim(substr2, "\n \t", 0);
		struc->flag_texture = true;
	}
	else if (!ft_strncmp(substr, "SO", 2) && struc->displ.count_so_path < 1)
	{
		if ((str[struc->index + 2] != ' ' && str[struc->index + 2] != '\t'))
			return (false);
		struc->displ.so_path = ft_strtrim(substr2, "\n \t", 0);
		struc->flag_texture = true;
	}
	else if (check_textures_part_we(struc, substr, substr2, str) == false)
		return (false);
	return (true);
}

void	check_texture(t_vars *struc, char *str)
{
	char	*substr;
	char	*substr2;
	char	*substr3;
	bool	check;
	int		i;

	check = true;
	struc->flag_texture = false;
	i = ignore_whitespaces(str);
	struc->index = i;
	substr = ft_substr(str, i, i + 2, 0);
	substr3 = ft_substr(str, i + 2, ft_strlen(str), 0);
	check = check_ceil_floor(struc, substr, substr3, str);
	substr2 = ft_substr(str, i + 3, ft_strlen(str), 0);
	if (check == false || check_textures_part_ns(struc, substr,
			substr2, str) == false)
		free_on_fail(struc, substr, substr2, substr3);
	if (struc->flag_texture == false && only_spaces(str) == false)
		free_on_fail(struc, substr, substr2, substr3);
	free(substr);
	free(substr2);
	free(substr3);
}
