/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:54:57 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/17 16:25:47 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static void	is_there_door(t_vars *struc)
{
	if (find_in_map_x(struc->map, 'D') != -1)
	{
		struc->door.nb_door = count_in_map(struc->map, 'D');
		struc->door.textures = mlx_load_png("textures/door.png");
		if (!struc->door.textures)
			error_texture_format(struc, "DOOR_CLOSED");
		struc->door.nb_alloc++;
		init_texture_tab_door(struc);
	}
}

static void	is_there_button(t_vars *struc)
{
	if (find_in_map_x(struc->map, 'B') != -1)
	{
		struc->button.nb_button = count_in_map(struc->map, 'B');
		struc->button.textures[0] = mlx_load_png("textures/button_off.png");
		if (!struc->button.textures[0])
			error_texture_format(struc, "BUTTON_OFF");
		struc->button.nb_alloc++;
		struc->button.textures[1] = mlx_load_png("textures/button_on.png");
		if (!struc->button.textures[1])
			error_texture_format(struc, "BUTTON_ON");
		struc->button.nb_alloc++;
		init_texture_tab_button(struc);
	}
}

static void	init_arr(t_vars *struc)
{
	struc->file = NULL;
	struc->map = NULL;
}

int	main(int argc, char **argv)
{
	t_vars		*struc;

	verif_args(argc, argv);
	struc = malloc(sizeof(t_vars));
	if (!struc)
		exit(EXIT_FAILURE);
	*struc = (t_vars){0};
	init_arr(struc);
	struc->file = parse_file(struc, argv[1]);
	init_sub_struct(struc);
	extract_file(struc);
	verif(struc);
	init_texture_tab(struc);
	find_player(struc);
	is_there_door(struc);
	is_there_button(struc);
	init_weapon(struc);
	display_window(struc);
	on_window_closed(struc);
	return (0);
}
