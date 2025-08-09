CXX			=	c++
CXXFLAGS	=	-std=c++98 -Wall -Werror -Wextra -Wshadow

NAME		=	Whatever

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) src/main.cpp -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
