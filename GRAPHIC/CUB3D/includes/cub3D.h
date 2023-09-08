/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:55:40 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/17 15:34:33 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include "ft_printf_fd.h"
# include "gnl.h"
# include "libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# include "../mlx/include/MLX42/MLX42.h"
# include "../mlx/include/MLX42/MLX42_Input.h"
# include "../mlx/include/MLX42/MLX42_Int.h"

/*---------------------Booleans-----------------------*/
# define TRUE 	1
# define FALSE 	0

/*---------------------Text_colors-----------------------*/
# define BLUE	 "\033[34m"
# define GREEN   "\033[32m"
# define RED     "\033[31m"
# define RESET   "\033[0m"

/*---------------------Rays_colors-----------------------*/
# define BROWN_C			0x61808C
# define GREEN_C			0X00a000FF
# define FLOOR_C			0xADD8E6FF
# define RED_C				0xFF0000FF
# define WALL_C 			0x000000FF
# define VOID 				0x00000000

/*---------------------Sizes-----------------------*/
# define HEIGHT 720
# define WIDTH 	1280
# define TEX_SIZE 64
# define TIME_STEP 1.0

/*---------------------Datas-----------------------*/
# define FOV_A 			66.0
# define MOVE_SPEED		0.075
# define ROTATE 		2.5
# define SQUARE 		15
# define TITLE 			"Quantumania"

# define PI 3.14159265358979323846

/*---------------------Structs-----------------------*/
typedef struct s_booleans
{
	bool		hit_wall;

}t_booleans;

typedef struct s_display
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	**ce_color;
	char	**fl_color;
	int		count_no_path;
	int		count_so_path;
	int		count_we_path;
	int		count_ea_path;
	int		count_ce_path;
	int		count_fl_path;
	int		total;
	int		ceilling[3];
	int		floor[3];

}t_display;

typedef struct s_image
{
	mlx_image_t		*cross_ptr;
	mlx_image_t		*game_ptr;
	mlx_image_t		*player_ptr;
	mlx_image_t		*ray_ptr;

}t_image;

typedef struct s_player
{
	float	x;
	float	y;

}t_player;

typedef struct s_ray
{
	double	camera_x;
	double	delta_dist_x;
	double	delta_dist_y;
	double	dir_x;
	double	dir_y;
	double	draw_start;
	double	draw_end;
	double	line_height;
	int		map_x;
	int		map_y;	
	double	perp_wall_dist;
	double	plane_x;
	double	plane_y;
	double	raydir_x;
	double	raydir_y;
	int		side;
	double	side_dist_x;
	double	side_dist_y;
	double	step_x;
	double	step_y;

}t_ray;

typedef struct s_wall
{
	int				nb_alloc;
	bool			orientation;
	double			step_x_column;
	double			step_y_column;
	int				tex_x;
	int				tex_y;
	double			tex_position_y;
	uint32_t		**texture_tab;
	mlx_texture_t	*textures[4];

}t_wall;

typedef struct s_vars
{
	t_booleans	booleans;
	t_display	displ;
	t_image		img;
	t_player	player;
	t_ray		ray;
	t_wall		wall;
	char		**file;
	char		**map;
	int			orientation;
	int			index;
	bool		flag_texture;
	mlx_t		*mlx_ptr;

}t_vars;

typedef struct s_vector
{
	int	x;
	int	y;

}t_vector;

typedef struct s_line
{
	int	start;
	int	end;

}t_line;

/*---------------------Display_f----------------------*/
void		display_fov(void *struc);
void		display_rotation(t_vars *struc);
void		display_rotation_void(t_vars *struc);
void		display_window(t_vars *struc);
void		draw_button(t_vars *struc, int column, t_line *pixel,
				int direction);
void		draw_column(t_vars *struc, int column, float wall_height);
void		draw_cross(t_vars *struc);
void		draw_door(t_vars *struc, int column, t_line *pixel, int direction);
void		draw_floor_sky(t_vars *struc, int column, t_line *pixel, int color);
void		draw_weapon(t_vars *struc, int column, t_line *pixel, int color);

/*---------------------Errors_f----------------------*/
void		error_closed_map(t_vars *struc);
void		error_component(t_vars *struc);
void		error_empty_file(t_vars *struc);
void		error_fail_texture(t_vars *struc);
void		error_extension(void);
void		error_nbr_args(void);
void		error_player_pos(t_vars *struc);
void		error_rgb(t_vars *struc, char *str);
void		error_texture_cub(t_vars *struc, char *str, int i);
void		error_texture_format(t_vars *struc, char *str);
void		error_missing_textures(t_vars *struc);
void		error_empty_line_map(t_vars *struc);

/*---------------------Free_f----------------------*/
void		free_arr_uint(uint32_t **arr);
void		free_on_fail(t_vars *struc, char *substr,
				char *substr2, char *substr3);
void		free_in_parsing(t_vars *struc);
void		free_in_verif_text_cub(t_vars *struc);
void		free_rgb(t_vars *struc, char *substr, char *substr2);
void		free_tab_and_textures(t_vars *struc);
void		free_textures(t_vars *struc);
void		on_window_closed(t_vars *struc);

/*---------------------Keys_f----------------------*/
void		on_key_pressed(void *struc);

/*---------------------Init_f----------------------*/
void		init_sub_struct(t_vars *struc);

/*---------------------Parsing_f----------------------*/
bool		check_color_floor(t_vars *struc, char *substr,
				char *substr2, char *str);
bool		check_color_ceil(t_vars *struc, char *substr,
				char *substr2, char *str);
void		check_texture(t_vars *struc, char *str);
bool		check_ceil_floor(t_vars *struc, char *substr,
				char *substr3, char *str);
bool		check_var_filled(t_vars *struc, bool finished);
void		extract_file(t_vars *struc);
char		**parse_file(t_vars *struc, char *file);

/*---------------------Mouse_f----------------------*/
void		on_mouse_move(void *struc);

/*---------------------Move_f----------------------*/
void		moves(t_vars *struc);
void		move_up(t_vars *struc);
void		move_down(t_vars *struc);
void		move_left(t_vars *struc);
void		move_right(t_vars *struc);
void		rotate(void *struc);
void		rotate_left(t_vars *struc);
void		rotate_right(t_vars *struc);

/*---------------------Textures_f----------------------*/
int			check_wall_side(t_vars *struc);
double		get_wall_text_x(t_vars *struc, int direction);
void		init_texture_tab(t_vars *struc);
uint32_t	rgb_to_int(uint32_t r, uint32_t g, uint32_t b, uint32_t a);

/*---------------------Verif_f----------------------*/
void		verif_args(int argc, char **argv);
bool		verif_ceil_floor(char **arr, char *substr, char *substr2);
bool		verif_closed_map(char **map);
bool		verif_components(char **map);
bool		verif_player_pos(char **map);
void		verif_rgb(t_vars *struc);
void		verif_texture_cub(t_vars *struc);
bool		verif_texture_format(t_vars *struc);
void		verif(t_vars *struc);

/*---------------------Utils_f----------------------*/
bool		compare_index(int x, int y, int x_cmp, int y_cmp);
bool		is_index_is_door(char **map, int x, int y);
bool		is_index_is_walkable(t_vars *struc, int y, int x);

int			count_in_map(char **map, int c);
int			find_in_map_x(char **map, int c);
int			find_in_map_y(char **map, int c);
void		find_player(t_vars *struc);
void		get_center_ray(t_vars *struc, int column, int *x, int *y);
int			get_highest(char **map);
int			get_longest(char **map);

bool		check_commas_format(char *substr);

int			ignore_whitespaces(char *s);
bool		only_spaces(char *str);
int			skip_spaces(char **file, int index);
bool		is_only_spaces(char **arr, int i);

int			check_wall_side(t_vars *struc);

#endif
