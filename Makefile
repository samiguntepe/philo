# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 18:32:40 by sguntepe          #+#    #+#              #
#    Updated: 2023/09/03 18:48:29 by sguntepe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SOURCE_FILES = main.c arg_parser.c other_utils.c

all:
    $(CC) $(CFLAGS) $(SOURCE_FILES) -o $(NAME) 

clean:
    rm -f $(NAME)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re