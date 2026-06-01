MAKEFLAGS	+=	-r -R

CXX			=	c++
CXXFLAGS	=	-std=c++20
CXXFLAGS	+=	-Wall -Werror -Wextra -Wshadow

NAME		=	Random

SRC			=	main.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) main.cpp -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
