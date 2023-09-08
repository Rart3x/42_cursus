NAME = zombies

SRC =	main.cpp \
		randomChump.cpp \
		newZombie.cpp \
		Zombie.cpp

OBJS	= $(SRC:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re 

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o	: %.cpp
	$(CC) $(FLAGS) $< -c -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all
