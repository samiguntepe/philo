# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguntepe <sguntepe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 18:32:40 by sguntepe          #+#    #+#              #
#    Updated: 2023/09/13 19:01:42 by sguntepe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCE_FILES = main.c arg_parser.c other_utils.c control.c time.c
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