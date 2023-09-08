/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:02:38 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/24 01:29:55 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	draw_button(t_vars *struc, int column, t_line *pixel, int direction)
{
	int	y;
	int	wall_size;
	int	text_y;
	int	color;

	wall_size = pixel->end - pixel->start;
	y = pixel->start;
	while (y < pixel->end)
	{
		if (y >= 0 && y < HEIGHT - 1)
		{
			text_y = ((float)(y - pixel->start) / wall_size)
				* struc->button.textures[direction]->width;
			color = struc->button.texture_tab[direction]
			[struc->button.tex_x + text_y
				* struc->button.textures[direction]->height];
			if (color != 0)
				mlx_put_pixel(struc->img.game_ptr, column, y, color);
		}
		y++;
	}
}

double	get_button_text_x(t_vars *struc, int direction)
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
	wall_text_x = (int)(wall_x * struc->button.textures[direction]->width);
	if (struc->button.orientation == false)
		wall_text_x = struc->button.textures[direction]->width
			- wall_text_x - 1;
	return (wall_text_x);
}

static uint32_t	*create_color_tab_button(t_vars *struc, int text_index)
{
	int			i;
	int			j;
	int			text_end;
	uint32_t	*text;

	i = 0;
	j = 0;
	text_end = struc->button.textures[text_index]->height
		* struc->button.textures[text_index]->width * 4;
	text = malloc(sizeof(uint32_t) * text_end / 4);
	while (i < text_end)
	{
		text[j] = rgb_to_int(struc->button.textures[text_index]->pixels[i],
				struc->button.textures[text_index]->pixels[i + 1],
				struc->button.textures[text_index]->pixels[i + 2],
				struc->button.textures[text_index]->pixels[i + 3]);
		i += 4;
		j++;
	}
	return (text);
}

void	init_texture_tab_button(t_vars *struc)
{
	int	i;

	i = 0;
	struc->button.texture_tab = malloc(sizeof(uint32_t *) * 3);
	while (i < 2)
	{
		struc->button.texture_tab[i] = create_color_tab_button(struc, i);
		i++;
	}
	struc->button.texture_tab[i] = NULL;
}

int	check_button_side(t_vars *struc)
{
	if (struc->map[struc->ray.map_y][struc->ray.map_x] == 'B'
		&& !struc->booleans.button)
	{
		struc->wall.orientation = true;
		return (5);
	}
	if (struc->map[struc->ray.map_y][struc->ray.map_x] == 'B'
		&& struc->booleans.button)
	{
		struc->wall.orientation = true;
		return (6);
	}
	return (0);
}
