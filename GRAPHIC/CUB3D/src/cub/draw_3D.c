/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:44:44 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/04 16:56:18 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_floor_sky(t_vars *struc, int column, t_line *pixel, int color)
{
	int	y;

	y = pixel->start;
	if (y < 0)
		y = 0;
	while (y < HEIGHT - 1 && y < pixel->end)
	{
		mlx_put_pixel(struc->img.game_ptr, column, y, color);
		y++;
	}
}

static void	draw_wall(t_vars *struc, int column, t_line *pixel, int direction)
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
				* struc->wall.textures[direction]->width;
			color = struc->wall.texture_tab[direction]
			[struc->wall.tex_x + text_y
				* struc->wall.textures[direction]->height];
			mlx_put_pixel(struc->img.game_ptr, column, y, color);
		}
		y++;
	}
}

static int	rgb_to_int_int(int red, int green, int blue)
{
	int	color;

	color = 0;
	color += red << 24;
	color += green << 16;
	color += blue << 8;
	color += 0xFF;
	return (color);
}

void	draw_column(t_vars *struc, int column, float wall_height)
{
	t_line		pixel;
	int			direction;
	int			color;

	pixel.start = 0;
	pixel.end = HEIGHT / 2;
	color = rgb_to_int_int(struc->displ.ceilling[0], struc->displ.ceilling[1],
			struc->displ.ceilling[2]);
	draw_floor_sky(struc, column, &pixel, color);
	pixel.start = HEIGHT / 2;
	pixel.end = HEIGHT;
	color = rgb_to_int_int(struc->displ.floor[0], struc->displ.floor[1],
			struc->displ.floor[2]);
	draw_floor_sky(struc, column, &pixel, color);
	direction = check_wall_side(struc);
	struc->wall.tex_x = get_wall_text_x(struc, direction);
	pixel.start = (HEIGHT / 2) - (wall_height);
	pixel.end = (HEIGHT / 2) + wall_height;
	draw_wall(struc, column, &pixel, direction);
}
