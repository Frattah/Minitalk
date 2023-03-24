# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 10:13:51 by frmonfre          #+#    #+#              #
#    Updated: 2023/03/16 10:13:56 by frmonfre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c	client.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -o3

all: libft server client

server:
	$(CC) $(CFLAGS) server.c libft/libft.a -o server

client:
	$(CC) $(CFLAGS) client.c libft/libft.a -o client

libft:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

bonus: all

.PHONY: all bonus libft clean fclean re
