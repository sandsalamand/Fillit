# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/12 16:50:11 by sgrindhe          #+#    #+#              #
#    Updated: 2018/08/20 23:05:55 by sgrindhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAG = -Wall -Werror -Wextra

NAME = fillit

LIBNAME = libft.a
LIBDIR	= libft

FILLIT	= fillit.c

SRC = utilities.c \
	  more_utilities.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBNAME)
	gcc $(CFLAG) -o $(NAME) $(FILLIT) $(SRC) -L$(LIBDIR) -lft

$(LIBNAME):
	@make -C $(LIBDIR)

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re: fclean $(NAME)

quick:
	rm -f $(NAME)
	gcc $(CFLAG) -o $(NAME) $(FILLIT) $(SRC) -L$(LIBDIR) -lft

.PHONY: clean fclean re


