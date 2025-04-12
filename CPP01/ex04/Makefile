CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME		=	Sed\ is\ for\ losers

SRC			=	main.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
