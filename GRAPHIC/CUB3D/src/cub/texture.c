/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:09:29 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/24 00:48:14 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	get_wall_text_x(t_vars *struc, int direction)
{
	double	wall_x;
	double	wall_text_x;

	wall_x = 0.0;
	if (struc->ray.side == 0)
	{
		wall_x = struc->player.y + struc->ray.perp_wall_dist
			* struc->ray.raydir_y;
	}
	else if (struc->ray.side == 1)
	{
		wall_x = struc->player.x + struc->ray.perp_wall_dist
			* struc->ray.raydir_x;
	}
	wall_x -= floor(wall_x);
	wall_text_x = (int)(wall_x * struc->wall.textures[direction]->width);
	if (struc->wall.orientation == false)
		wall_text_x = struc->wall.textures[direction]->width - wall_text_x - 1;
	return (wall_text_x);
}

uint32_t	rgb_to_int(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	uint32_t	color;

	color = 0;
	color += r << 24;
	color += g << 16;
	color += b << 8;
	color += a;
	return (color);
}

static uint32_t	*create_color_tab(t_vars *struc, int text_index)
{
	int			i;
	int			j;
	int			text_end;
	uint32_t	*text;

	i = 0;
	j = 0;
	text_end = struc->wall.textures[text_index]->height
		* struc->wall.textures[text_index]->width * 4;
	text = malloc(sizeof(uint32_t) * text_end / 4);
	while (i < text_end)
	{
		text[j] = rgb_to_int(struc->wall.textures[text_index]->pixels[i],
				struc->wall.textures[text_index]->pixels[i + 1],
				struc->wall.textures[text_index]->pixels[i + 2],
				struc->wall.textures[text_index]->pixels[i + 3]);
		i += 4;
		j++;
	}
	return (text);
}

void	init_texture_tab(t_vars *struc)
{
	int	i;

	i = 0;
	struc->wall.texture_tab = malloc(sizeof(uint32_t *) * 5);
	while (i < 4)
	{
		struc->wall.texture_tab[i] = create_color_tab(struc, i);
		i++;
	}
	struc->wall.texture_tab[i] = NULL;
}
