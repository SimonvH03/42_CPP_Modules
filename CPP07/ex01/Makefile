CXX			=	c++
CXXFLAGS	=	-std=c++11 -Wall -Werror -Wextra -Wshadow

NAME		=	Iter

all: $(NAME)

$(NAME): main.cpp iter.hpp iterRef.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all

.PHONY: all clean fclean re
