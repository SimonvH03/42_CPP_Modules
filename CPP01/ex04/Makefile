CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME	=	Sed\ is\ for\ losers

SRC		=	main.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
