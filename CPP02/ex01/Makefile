CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME		=	Towards\ a\ more\ useful\ fixed-point\ number\ class

HDR			=	Fixed.hpp

SRC			=	main.cpp \
				Fixed.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
