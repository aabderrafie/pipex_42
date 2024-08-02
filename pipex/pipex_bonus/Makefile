# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 15:08:06 by aaskal            #+#    #+#              #
#    Updated: 2024/03/27 00:35:03 by aaskal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCB = pipex_bonus.c ft_error_bonus.c  get_full_path_bonus.c execute_command_bonus.c split_command_bonus.c handle_here_doc_bonus.c \
	  getnextline/get_next_line.c getnextline/get_next_line_utils.c

OBJB = $(SRCB:.c=.o)


NAME = pipex

LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJB)
	@$(MAKE) -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJB) $(LIBFT)



%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(MAKE) -C  ../libft clean
	rm -f $(OBJB)

fclean: clean
	@$(MAKE) -C ../libft fclean
	rm -f $(NAME) 

re: fclean all

42: all  clean 

.PHONY: all clean fclean re