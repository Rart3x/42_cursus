/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:10 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 15:08:25 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_vars *struc)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(struc->mlx, struc->images[i].ptr);
		i++;
	}
}
