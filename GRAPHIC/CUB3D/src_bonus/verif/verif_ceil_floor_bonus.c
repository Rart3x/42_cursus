/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_ceil_floor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:43:51 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/03 13:19:54 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

bool	verif_ceil_floor(char **arr, char *substr, char *substr2)
{
	int	i;

	i = -1;
	if (!arr)
	{
		free(substr);
		free(substr2);
		return (false);
	}
	while (arr[++i])
	{
		if (arr[i][0] == '\0' || arr[i][0] == '\n'
			|| ft_atoi(arr[i]) > 255 || ft_atoi(arr[i]) < 0)
		{
			free(substr);
			free(substr2);
			return (false);
		}
	}
	return (true);
}
