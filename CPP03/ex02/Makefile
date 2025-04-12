CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++11

NAME		=	Repetitive\ work

HDR			=	ClapTrap.hpp \
				FragTrap.hpp \
				ScavTrap.hpp

SRC			=	ClapTrap.cpp \
				FragTrap.cpp \
				ScavTrap.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR) main.cpp
	$(CXX) $(CXXFLAGS) $(SRC) main.cpp -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
