CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	Unnecessary\ violence

HDR		=	Weapon.hpp \
			HumanA.hpp \
			HumanB.hpp

SRC		=	Weapon.cpp \
			HumanA.cpp \
			HumanB.cpp
			main.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re