CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME		=	Moar\ brainz!

HDR			=	Zombie.hpp

SRC			=	main.cpp \
				Zombie.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re