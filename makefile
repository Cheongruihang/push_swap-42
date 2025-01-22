NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ) libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re

