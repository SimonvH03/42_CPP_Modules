CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	Unnecessary\ violence

HDR		=	HumanA.hpp \
			HumanB.hpp \
			Weapon.hpp

SRC		=	HumanA.cpp \
			HumanB.cpp \
			main.cpp \
			Weapon.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
