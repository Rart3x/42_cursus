/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:54:57 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/17 16:56:01 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
	display_window(struc);
	on_window_closed(struc);
	return (0);
}
