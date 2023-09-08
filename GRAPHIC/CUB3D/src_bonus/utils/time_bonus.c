/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:09:39 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/20 21:25:12 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	tempo_texture(t_vars *struc)
{
	if (struc->booleans.door_open == true
		&& struc->booleans.door_animation == true)
	{
		struc->booleans.door_open = false;
		struc->booleans.door_animation = false;
	}
	else if (!struc->booleans.door_open
		&& struc->booleans.door_animation == true)
	{
		struc->booleans.door_open = true;
		struc->booleans.door_animation = false;
	}
}
