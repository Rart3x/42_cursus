/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:01:57 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/17 17:01:42 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

bool	check_ceil_floor(t_vars *struc, char *substr, char *substr3, char *str)
{
	bool	check;

	check = true;
	if (!ft_strncmp(substr, "C", 1) && struc->displ.count_ce_path < 1)
	{
		check = check_color_ceil(struc, substr, substr3, str);
		struc->flag_texture = true;
	}
	else if (!ft_strncmp(substr, "F", 1) && struc->displ.count_fl_path < 1)
	{
		check = check_color_floor(struc, substr, substr3, str);
		struc->flag_texture = true;
	}
	return (check);
}
