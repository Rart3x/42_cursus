NAME = megaphone

SRC = megaphone.cpp

OBJS	= $(SRC:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re 

all : $(NAME)

%.o	: %.cpp
	$(CC) $(FLAGS) $< -c -o $@

clean:
		rm -rf $(OBJS)
fclean: clean
		rm -rf $(NAME)

re: fclean all
