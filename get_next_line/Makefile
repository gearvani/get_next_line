# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/09 16:51:32 by georgios-ar       #+#    #+#              #
#    Updated: 2026/10/09 16:51:35 by georgios-ar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42

COMPILE = $(CC) $(CFLAGS) -c

LIB = ar -rcs $(NAME)

%.o : %.c
	$(COMPILE) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(OBJ)
	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all