/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:33:16 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/24 17:02:42 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
/*--------------------SO_LONG---------------*/
/*------Structs------*/

typedef struct s_image
{
	void	*ptr;
}t_image;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		lines_map;
	int		width;
	int		height;
	int		movements;
	int		w_exit;
	t_image	images[5];
}t_vars;

/*-------Init------*/
void	init_image(t_vars *struc);
/*-------Checks------*/
int		check_components(char **map);
int		check_rectangular(char **map, int fd);
int		check_required(char **map);
int		check_walls(char **map, int fd);
int		check_path(char **map);
void	check_check(char **map, int fd, char *file);
/*-------Errors------*/
void	error_exit_start(char **map, int exit, int start_pos);
void	error_rect(char **map);
void	error_required(char **map);
void	error_walls(char **map);
void	error_components(char **map);
/*-------Display------*/
void	*display_path(t_vars *struc, int x, int y);
void	*display_wall(t_vars *struc, int x, int y);
void	*display_collectible(t_vars *struc, int x, int y);
void	*display_exit(t_vars *struc, int x, int y);
void	*display_player(t_vars *struc, int x, int y);
void	display_window(t_vars *struc);
void	display_map(t_vars *struc);
/*-------Map------*/
char	**parse_map(char *file);
int		line_in_file(int fd);
/*-------Window------*/
int		on_window_closed(t_vars *struc);
int		on_key_pressed(int key, t_vars *struc);
int		window_width(char **map);
int		window_height(char **map);
/*-------Movements------*/
void	move_up(t_vars *struc);
void	move_down(t_vars *struc);
void	move_left(t_vars *struc);
void	move_right(t_vars *struc);
char	*move_count(int movements);
void	move_print(t_vars *struc);
/*-------Find------*/
int		find_collectible(char **cpy_map);
int		find_start_x(char **cpy_map);
int		find_start_y(char **cpy_map);
int		find_exit(char **cpy_map);
/*-------Utils------*/
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	**copy_tab_tab(char **tab);
int		ft_strlen(char *str);
int		ft_strrchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup(char *src);
/*-------Win------*/
void	win(t_vars *struc);
/*-------Destroy------*/
void	destroy_img(t_vars *struc);
/*-------Free------*/
void	free_tab_tab(char **tab);
/*--------------Char------------------*/
char	**ft_split_pf(char const *s, char c);
char	*ft_strjoin_pf(char *s1, char *s2);
char	*ft_strrchr_pf(const char *s, int c);
/*--------------Int------------------*/
int		ft_printf(const char *format, ...);
int		ft_put_unsigned_nbr(unsigned int n);
int		ft_putnbr_base(long n, char *base);
int		ft_putchar_printf(int c);
int		ft_putstr_printf(char *s);
int		ft_putnbr_printf(int nb);

#endif
