NAME = libftprintf.a

CC = clang

SRC = 	  ft_printf_fd.c \
		  ft_function.c \
		  ft_function2.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o : %.c
	clang $(CFLAGS) $< -c -o $@

clean: 
	@rm -rf $(OBJ) $(OBJB)
fclean: clean 
	@rm -rf $(NAME)
re: fclean all 

.PHONY: all clean fclean re 
