CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	Towards\ a\ more\ useful\ fixed-point\ number\ class

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
