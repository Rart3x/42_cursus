/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:21:02 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/16 02:55:54 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	extract_map(t_vars *struc, int i)
{
	int	j;
	int	tmp;

	j = 0;
	tmp = i;
	while (struc->file[i] && only_spaces(struc->file[i]) == false)
	{
		i++;
		j++;
	}
	if (is_only_spaces(struc->file, i) == false)
		error_empty_line_map(struc);
	struc->map = malloc(sizeof(char *) * (j + 1));
	j = 0;
	i = tmp;
	while (struc->file[i] && only_spaces(struc->file[i]) == false)
	{
		struc->map[j] = strdup(struc->file[i]);
		i++;
		j++;
	}
	struc->map[j] = NULL;
}

void	extract_file(t_vars *struc)
{
	int	i;

	i = 0;
	while (struc->file[i])
	{
		check_texture(struc, struc->file[i]);
		if (check_var_filled(struc, false) == true)
		{
			i++;
			break ;
		}
		i++;
	}
	if (check_var_filled(struc, true) == false)
		error_missing_textures(struc);
	i = i + skip_spaces(struc->file, i);
	while (struc->file[i])
	{
		if (only_spaces(struc->file[i]) == false)
			break ;
		i++;
	}
	extract_map(struc, i);
}
