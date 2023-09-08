/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:47:28 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/20 22:10:04 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static bool	is_component(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == 32
		|| c == 'D' || c == '\n' || c == '\0'
		|| c == 'B')
		return (true);
	return (false);
}

bool	verif_components(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_component(map[i][j]) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
