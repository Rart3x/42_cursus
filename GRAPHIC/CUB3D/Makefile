# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 17:07:15 by kramjatt          #+#    #+#              #
#    Updated: 2023/08/17 15:16:08 by kramjatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

CC = clang
CFLAGS = -Wall -Wextra -Werror -g -Ofast -gdwarf-2

SRC_DIR = src
SRC_DIR_BONUS = src_bonus

SRC = 	src/cub/cub3D.c					src/cub/display_window.c		src/cub/check_wall_side.c			\
		src/cub/extract_file.c			src/cub/parse_map.c				src/cub/draw_3D.c					\
		src/cub/move_player.c			src/cub/draw_functions.c		src/cub/ray.c						\
		src/cub/rotation.c				src/cub/texture.c				src/cub/parse_texture.c				\
		src/cub/keys.c					src/cub/parse_texture_utils.c																    \

SRC+=	src/errors/errors_map.c			src/errors/errors_texture.c		src/errors/errors_empty_file.c		\

SRC+=	src/utils/find_in_map.c			src/utils/frees.c				src/utils/get_functions.c			\
		src/utils/init.c				src/utils/whitespaces.c			src/utils/compare_index.c			\
		src/utils/free_functions.c		src/utils/count_in_map.c											\

SRC+=	src/verif/verif_closed_map.c	src/verif/verif_player_pos.c	src/verif/verif_texture_format.c 	\
		src/verif/verif_rgb.c 			src/verif/verif_components.c	src/verif/verif_args.c				\
		src/verif/verif.c				src/verif/verif_ceil_floor.c	src/verif/check.c					\

SRC+=	src/gnl/gnl.c					src/gnl/gnl_utils.c 												\

SRC+=	src/libft/count_args2d.c		src/libft/cpy_array2d.c		src/libft/free_array2d.c 				\
		src/libft/ft_putstr_fd.c		src/libft/ft_strcpy.c		src/libft/ft_strlen.c					\
		src/libft/ft_strncmp.c			src/libft/ft_substr.c		src/libft/print_array2d.c				\
		src/libft/ft_split.c			src/libft/ft_atoi.c			src/libft/ft_strtrim.c					\
		src/libft/ft_strlen_trim.c																			\

SRC_BONUS = 	src_bonus/cub/cub3D_bonus.c						src_bonus/cub/display_window_bonus.c															\
				src_bonus/cub/extract_file_bonus.c				src_bonus/cub/parse_map_bonus.c					src_bonus/cub/draw_3D_bonus.c					\
				src_bonus/cub/move_player_bonus.c				src_bonus/cub/draw_functions_bonus.c			src_bonus/cub/ray_bonus.c						\
				src_bonus/cub/rotation_bonus.c					src_bonus/cub/texture_bonus.c					src_bonus/cub/door_bonus.c						\
				src_bonus/cub/mouse_bonus.c						src_bonus/cub/keys_bonus.c						src_bonus/cub/parse_texture_bonus.c				\
				src_bonus/cub/button_bonus.c 					src_bonus/cub/animation_bonus.c					src_bonus/cub/check_wall_side_bonus.c			\
				src_bonus/cub/parse_texture_utils_bonus.c

SRC_BONUS+=		src_bonus/errors/errors_map_bonus.c				src_bonus/errors/errors_texture_bonus.c			src_bonus/errors/errors_empty_file_bonus.c		\

SRC_BONUS+=		src_bonus/utils/find_in_map_bonus.c				src_bonus/utils/frees_bonus.c					src_bonus/utils/get_functions_bonus.c			\
				src_bonus/utils/init_bonus.c					src_bonus/utils/whitespaces_bonus.c				src_bonus/utils/compare_index_bonus.c			\
				src_bonus/utils/time_bonus.c					src_bonus/utils/free_functions_bonus.c			src_bonus/utils/count_in_map_bonus.c			\

SRC_BONUS+=		src_bonus/verif/verif_closed_map_bonus.c		src_bonus/verif/verif_player_pos_bonus.c		src_bonus/verif/verif_texture_format_bonus.c 	\
				src_bonus/verif/verif_rgb_bonus.c 				src_bonus/verif/verif_components_bonus.c		src_bonus/verif/verif_args_bonus.c				\
				src_bonus/verif/verif_bonus.c					src_bonus/verif/verif_ceil_floor_bonus.c		src_bonus/verif/check_bonus.c					\

SRC_BONUS+=		src_bonus/gnl/gnl.c								src_bonus/gnl/gnl_utils.c 																		\

SRC_BONUS+=		src_bonus/libft/count_args2d.c					src_bonus/libft/cpy_array2d.c		src_bonus/libft/free_array2d.c 								\
				src_bonus/libft/ft_putstr_fd.c					src_bonus/libft/ft_strcpy.c			src_bonus/libft/ft_strlen.c									\
				src_bonus/libft/ft_strncmp.c					src_bonus/libft/ft_substr.c			src_bonus/libft/print_array2d.c								\
				src_bonus/libft/ft_split.c						src_bonus/libft/ft_atoi.c			src_bonus/libft/ft_strtrim.c								\
				src_bonus/libft/ft_strlen_trim.c																												\

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

.PHONY: all clean fclean re reb

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	@make -C src/ft_printf_fd
	@cmake mlx -B mlx/build
	@make -C mlx/build/ -j4
	@$(CC) $(CFLAGS) $(OBJ) mlx/build/libmlx42.a -Iinclude -ldl -lglfw src/ft_printf_fd/libftprintf.a -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	@make -C src_bonus/ft_printf_fd
	@cmake mlx -B mlx/build
	@make -C mlx/build/ -j4
	@$(CC) $(CFLAGS) $(OBJ_BONUS) mlx/build/libmlx42.a -Iinclude -ldl -lglfw src_bonus/ft_printf_fd/libftprintf.a -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -o $@ -c $<

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c | $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@make clean -C mlx/build
	@make clean -C src/ft_printf_fd
	@make clean -C src_bonus/ft_printf_fd

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C src/ft_printf_fd
	@make fclean -C src_bonus/ft_printf_fd

re: fclean all

reb :fclean bonus
