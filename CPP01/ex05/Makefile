CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME	=	Harl\ 2.0

HDR		=	Harl.hpp

SRC		=	Harl.cpp \
			main.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
