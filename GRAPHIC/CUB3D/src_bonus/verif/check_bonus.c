/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gazzopar <gazzopar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:39:20 by gazzopar          #+#    #+#             */
/*   Updated: 2023/08/07 15:42:35 by gazzopar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	check_commas_format(char *substr)
{
	int	i;

	i = 0;
	while (substr && substr[i])
	{
		if (substr[i] == ',' && substr[i + 1] == ',')
			return (false);
		i++;
	}
	return (true);
}
