CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	HI\ THIS\ IS\ BRAIN

SRC		=	main.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re