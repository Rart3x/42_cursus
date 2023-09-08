NAME = libft.a

CC = gcc

SRC = 	  ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strdup.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putnbr_fd.c \
	  ft_putendl_fd.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strjoin.c 

SRCB = 	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
		 ar rc $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJB)
	ar rc libft.a $(OBJ) $(OBJB)

%.o : %.c
	gcc $(CFLAGS) $< -c -o $@
clean: 
	rm -rf $(OBJ) $(OBJB)
	echo "Suppression de l'ensemble des fichiers -o"
fclean: clean 
		rm -rf $(NAME)
		echo "Suppression de l'ensemble des fichiers"
re: fclean all 

.PHONY: all clean fclean re 

run: $(OBJ)
	gcc $(OBJ) main.c -o test
	./test

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRCB)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJB)
