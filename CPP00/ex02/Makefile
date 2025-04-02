CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME	=	MissingFileTest

HDR		=	Account.hpp \

SRC		=	Account.cpp \
			tests.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re