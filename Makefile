SRCS = server.c	client.c

OBJS = $(SRCS:.c=.o)

all: libft server client

server:
	cc server.c libft/libft.a -o server

client:
	cc client.c libft/libft.a -o client

libft:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re