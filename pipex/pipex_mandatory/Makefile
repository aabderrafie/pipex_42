# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 15:08:06 by aaskal            #+#    #+#              #
#    Updated: 2024/03/27 00:35:41 by aaskal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c ft_error.c  get_full_path.c execute_command.c split_command.c

OBJ = $(SRC:.c=.o)


NAME = pipex

LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)



%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(MAKE) -C ../libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C	../libft fclean
	rm -f $(NAME) 

re: fclean all
42: all  clean 


.PHONY: all clean fclean re