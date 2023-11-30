# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 11:08:54 by kramjatt          #+#    #+#              #
#    Updated: 2023/08/28 02:34:06 by kramjatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SRC = main.cpp BitcoinExchange.cpp \

OBJS	= $(SRC:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g

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
