CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	file

HDR		=	file.hpp

SRC		=	file.cpp \
			main.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
