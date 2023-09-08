NAME = push_swap
NAME_BONUS = checker

CC = clang

NAME = push_swap
NAME_BONUS = checker

SRC_DIR = src
SRC_DIR_BONUS = bonus

SRC = 	  src/alloc_functions.c \
	  src/check_args.c \
	  src/errors.c \
	  src/exceptions.c \
	  src/free_functions.c \
	  src/ft_atoi.c \
	  src/ft_bzero.c \
	  src/ft_calloc.c \
	  src/ft_memcpy.c \
	  src/ft_memset.c \
	  src/ft_split.c \
	  src/ft_strcpy_int_tab.c \
	  src/ft_strjoin.c \
	  src/ft_strlen.c \
	  src/manip_int_tab.c \
	  src/mini_sort.c \
	  src/push_functions.c \
	  src/push_swap.c \
	  src/reverse_rotate_functions.c \
	  src/rotate_functions.c \
	  src/sort.c \
	  src/sort_100.c \
	  src/sort_500.c \
	  src/swap_functions.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = bonus/alloc_functions.c \
	  bonus/check_args.c \
	  bonus/checker.c \
	  bonus/errors.c \
	  bonus/exceptions.c \
	  bonus/free_functions.c \
	  bonus/ft_atoi.c \
	  bonus/ft_bzero.c \
	  bonus/ft_calloc.c \
	  bonus/ft_memcpy.c \
	  bonus/ft_memset.c \
	  bonus/ft_split.c \
	  bonus/ft_strcpy_int_tab.c \
	  bonus/ft_strjoin.c \
	  bonus/ft_strlen.c \
	  bonus/get_next_line.c \
	  bonus/get_next_line_utils.c \
	  bonus/manip_int_tab.c \
	  bonus/mini_sort.c \
	  bonus/push_functions.c \
	  bonus/push_swap.c \
	  bonus/reverse_rotate_functions.c \
	  bonus/rotate_functions.c \
	  bonus/swap_functions.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJ)
	@echo "###########################################################################"
	@echo "Compilation de $(NAME) terminée"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "###########################################################################"
	@echo "Compilation de $(NAME_BONUS) terminée"
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c | $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all bonus
