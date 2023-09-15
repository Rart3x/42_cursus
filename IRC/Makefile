# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 09:23:48 by nicarpen          #+#    #+#              #
#    Updated: 2023/09/06 08:36:56 by kramjatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#Utilities

RM				= rm -rf
DIR_DUP			= mkdir -p $(@D)
OBJS_DIR		= .objs/
SRCS_DIR		=
green			= /bin/echo -e "\x1b[32m$1\x1b[0m"

################################################################################
#Program (program's name, sources)

NAME		= ircserv
BONUS		= bot

MAIN_SRC=			srcs/main.cpp					\
					srcs/Channel.cpp				\
					srcs/Client.cpp					\
					srcs/Command.cpp				\
					srcs/Mode.cpp					\
					srcs/Server.cpp					\

BONUS_SRC=			srcs/Bot.cpp					\
					srcs/Channel.cpp				\
					srcs/Client.cpp					\
					srcs/Command.cpp				\
					srcs/bonus.cpp					\
					srcs/Mode.cpp					\
					srcs/Server.cpp					\


################################################################################
#Compilation

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS = $(addprefix $(SRCS_DIR), $(MAIN_SRC))
SRCS_BONUS = $(addprefix $(SRCS_DIR), $(BONUS_SRC))

OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
OBJS_BONUS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_BONUS))

################################################################################
#Rules

all: $(NAME)
bot: $(BONUS)
both: $(NAME) $(BONUS)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -Iincludes -c $< -o $@

${NAME}: ${OBJS}
	@echo " "
	@$(call green,"Compilation OBJ done ")
	@echo "Compilation ${NAME} :"
	$(CC) $^ $(CFLAGS) -o $(NAME)
	@$(call green,"Compilation finish : $(NAME) is created ")
	@echo " "

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -Iincludes -c $< -o $@

${BONUS}: ${OBJS_BONUS}
	@echo " "
	@$(call green,"Compilation OBJ done ")
	@echo "Compilation ${BONUS} :"
	$(CC) $^ $(CFLAGS) -o $(BONUS)
	@$(call green,"Compilation finish : $(BONUS) is created ")
	@echo " "

$(OBJS): | $(OBJS_DIR)
$(OBJS_BONUS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean:
	@$(RM) $(OBJS_DIR)
	@$(call green,"Clean OBJ done ")

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@$(call green,"Fclean $(NAME) done ")

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all

reb:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory bot

.PHONY: all clean fclean re
