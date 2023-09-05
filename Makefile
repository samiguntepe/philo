# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 18:32:40 by sguntepe          #+#    #+#              #
#    Updated: 2023/09/05 13:14:15 by sguntepe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCE_FILES = main.c arg_parser.c other_utils.c control.c
GREEN	= \033[0;32m
RED		= \033[0;31m
Q = \033[m

all:
	@$(CC) $(CFLAGS) $(SOURCE_FILES) -o $(NAME)
	@echo "$(GREEN)[✓]$(Q)"

clean:
	@rm -f $(NAME)
	@echo "$(RED)[DELETED]$(Q)"

fclean: clean
	@rm -f $(NAME)
	

re: fclean all

.PHONY: all clean fclean re