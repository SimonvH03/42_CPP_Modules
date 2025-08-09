CXX			=	c++
CXXFLAGS	=	-std=c++98 -Wall -Werror -Wextra -Wshadow

NAME		=	Iter

all: $(NAME)

$(NAME): main.cpp iter.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
