CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME		=	Serena,\ my\ love!

HDR			=	ClapTrap.hpp \
				ScavTrap.hpp

SRC			=	ClapTrap.cpp \
				ScavTrap.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR) main.cpp
	$(CXX) $(CXXFLAGS) $(SRC) main.cpp -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
