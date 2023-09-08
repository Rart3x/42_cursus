/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:42:44 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/16 16:04:02 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_displ(t_vars *struc)
{
	struc->displ.no_path = NULL;
	struc->displ.so_path = NULL;
	struc->displ.we_path = NULL;
	struc->displ.ea_path = NULL;
	struc->displ.ce_color = NULL;
	struc->displ.fl_color = NULL;
	struc->displ.count_no_path = 0;
	struc->displ.count_so_path = 0;
	struc->displ.count_we_path = 0;
	struc->displ.count_ea_path = 0;
	struc->displ.count_ce_path = 0;
	struc->displ.count_fl_path = 0;
	struc->displ.total = 0;
}

void	init_sub_struct(t_vars *struc)
{	
	struc->booleans.hit_wall = false;
	struc->player.x = 0;
	struc->player.y = 0;
	struc->ray.draw_end = 0;
	struc->ray.draw_start = 0;
	struc->ray.line_height = 0;
	struc->wall.nb_alloc = 0;
	struc->wall.textures[0] = NULL;
	struc->wall.textures[1] = NULL;
	struc->wall.textures[2] = NULL;
	struc->wall.textures[3] = NULL;
	init_displ(struc);
}
