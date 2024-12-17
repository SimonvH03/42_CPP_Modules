CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	Serena,\ my\ love!

HDR		=	ClapTrap.hpp \
			ScavTrap.hpp

SRC		=	ClapTrap.cpp \
			main.cpp \
			ScavTrap.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
