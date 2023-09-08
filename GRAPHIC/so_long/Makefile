NAME = so_long

CC = clang

SRC_DIR = src

SRC = 	  src/check_check.c \
		  src/check_components.c \
		  src/check_path.c \
		  src/check_rectangular.c \
		  src/check_required.c \
		  src/check_walls.c \
		  src/copy_tab_tab.c \
		  src/destroy_img.c \
		  src/display_map.c \
		  src/display_window.c \
		  src/errors.c \
		  src/extract_map.c \
		  src/find_functions.c \
		  src/free_functions.c \
		  src/ft_itoa.c \
		  src/ft_strdup.c \
		  src/ft_strjoin.c \
		  src/get_next_line.c \
		  src/get_next_line_utils.c \
		  src/init_functions.c \
		  src/move_player.c \
		  src/move_utils.c \
		  src/so_long.c \
		  src/win.c \
		  src/window_size.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx-linux
	@make -C printf
	@echo "Compilation de $(NAME) terminée"
	@$(CC) $(CFLAGS) $(OBJ) minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a printf/libftprintf.a -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@make clean -C printf
	@make clean -C minilibx-linux

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C printf
re: fclean all
