CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME		=	Aaaaand...\ OPEN!

HDR			=	ClapTrap.hpp

SRC			=	ClapTrap.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR) main.cpp
	$(CXX) $(CXXFLAGS) $(SRC) main.cpp -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
