/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:17:43 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/18 22:13:47 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars		struc;

	if (argc < 2)
		return (0);
	struc.movements = 0;
	struc.map = parse_map(argv[1]);
	if (!struc.map)
		return (0);
	if (check_path(struc.map) == 0)
	{
		free_tab_tab(struc.map);
		write(2, "Error\nNeeded 1 path valid on map\n", 33);
		return (0);
	}
	struc.mlx = mlx_init();
	init_image(&struc);
	display_window(&struc);
	destroy_img(&struc);
	return (0);
}
