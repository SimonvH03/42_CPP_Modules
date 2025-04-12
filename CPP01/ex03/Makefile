CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME		=	Unnecessary\ violence

HDR			=	HumanA.hpp \
				HumanB.hpp \
				Weapon.hpp

SRC			=	main.cpp \
				HumanA.cpp \
				HumanB.cpp \
				Weapon.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
