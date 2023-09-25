# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 18:32:40 by sguntepe          #+#    #+#              #
#    Updated: 2023/09/25 19:38:42 by sguntepe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SOURCE_FILES = main.c arg_parser.c other_utils.c control.c time.c inits.c \
			dinner_utils.c dinner.c write_terminal.c
GREEN	= \033[0;32m
RED		= \033[0;31m
CODE = \033[m

all:
	@$(CC) $(CFLAGS) $(SOURCE_FILES) -o $(NAME)
	@echo "$(GREEN)[✓]$(CODE)"

clean:
	@rm -f $(NAME)
	@echo "$(RED)[DELETED]$(CODE)"

fclean: clean
	@rm -f $(NAME)
	

re: fclean all

.PHONY: all clean fclean re