CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME	=	MyAwesomePhoneBook

HDR		=	PhoneBook.hpp \
			Contact.hpp

SRC		=	PhoneBook.cpp \
			Contact.cpp \
			main.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re