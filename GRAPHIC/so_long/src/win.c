/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:12:55 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 18:34:32 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_vars *struc)
{
	ft_printf("Congratulations !\n");
	destroy_img(struc);
	mlx_destroy_window(struc->mlx, struc->win);
	mlx_destroy_display(struc->mlx);
	free_tab_tab(struc->map);
	free(struc->mlx);
	exit(EXIT_SUCCESS);
}
