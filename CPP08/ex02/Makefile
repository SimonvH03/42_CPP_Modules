CXX			=	c++
CXXFLAGS	=	-std=c++11 -Wall -Werror -Wextra -Wshadow

NAME		=	Mutated

all: $(NAME)

$(NAME): main.cpp MutantStack.hpp MutantStack.tpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
