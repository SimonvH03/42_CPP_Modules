NAME		=	MyAwesomePhoneBook

CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

HDR			=	Contact.hpp \
				PhoneBook.hpp

SRC			=	main.cpp \
				Contact.cpp \
				PhoneBook.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re