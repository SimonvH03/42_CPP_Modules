CXX			=	c++
CXXFLAGS	=	-std=c++11 -Wall -Werror -Wextra -Wshadow

NAME		=	Easy

all: $(NAME)

$(NAME): main.cpp easyfind.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
