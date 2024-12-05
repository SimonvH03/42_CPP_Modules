CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	My\ First\ Class\ in\ Orthodox\ Canonical\ Form

HDR		=	Fixed.hpp

SRC		=	Fixed.cpp \
			main.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
