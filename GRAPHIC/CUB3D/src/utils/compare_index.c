/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:14:59 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/02 19:28:49 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	compare_index(int x, int y, int x_cmp, int y_cmp)
{
	if (x == x_cmp && y == y_cmp)
		return (true);
	return (false);
}

bool	is_index_is_walkable(t_vars *struc, int y, int x)
{
	if (struc->map[y][x] == '1')
		return (true);
	return (false);
}
