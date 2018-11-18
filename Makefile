# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnakar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/29 10:39:48 by mnakar            #+#    #+#              #
#    Updated: 2018/07/30 10:04:23 by mnakar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

CFLAGS = -Wall -Wextra -Werror

FILES = main.c 

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME) :
	#make -C $(LIBFT)
	gcc $(CFLAGS) -c $(FILES) 
	gcc $(OBJ) -o $(NAME) -L. -lftprintf

clean:
	#make clean -C $(LIBFT)
	rm -f *.o

fclean: clean
	#make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

test:
	gcc -g -o ft_ssl $(FILES) -L. -lftprintf -L. -lft

.PHONY: all clean fclean re
