NAME = libftprintf.a

CC = clang

SRC = 	  ft_printf.c \
		  ft_function.c \
		  ft_function2.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
		 ar rc $(NAME) $(OBJ)
		 @echo "Compilation de $(NAME) terminée"

%.o : %.c
	clang $(CFLAGS) $< -c -o $@

clean: 
	@rm -rf $(OBJ) $(OBJB)
	@echo "Suppression de l'ensemble des fichiers -o"
fclean: clean 
	rm -rf $(NAME)
	@echo "Suppression de l'ensemble des fichiers"
re: fclean all 

.PHONY: all clean fclean re 
