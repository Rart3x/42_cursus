CC = cc -g

CFLAGS = -Wall -Werror -Wextra

SRCS = 	main.c error.c ft_convert.c ft_str.c read_file.c
	
NAME = rush-02

RM = rm -f

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}

clean:
	${RM} ${NAME}

fclean: clean

re : fclean all

.PHONY: all clean fclean re
