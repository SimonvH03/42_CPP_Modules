CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	I\ don\'t\ want\ to\ set\ the\ world\ on\ fire

CLS_DIR	=	./classes

HDR		=	$(CLS_DIR)/Animal.hpp \
			$(CLS_DIR)/Brain.hpp \
			$(CLS_DIR)/Cat.hpp \
			$(CLS_DIR)/Dog.hpp \
			$(CLS_DIR)/WrongCat.hpp \
			$(CLS_DIR)/WrongAnimal.hpp

SRC		=	$(CLS_DIR)/Animal.cpp \
			$(CLS_DIR)/Brain.cpp \
			$(CLS_DIR)/Cat.cpp \
			$(CLS_DIR)/Dog.cpp \
			$(CLS_DIR)/WrongCat.cpp \
			$(CLS_DIR)/WrongAnimal.cpp

OBJ_DIR	=	./objects
OBJ		=	$(SRC:$(CLS_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(CLS_DIR)/%.cpp $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(HDR) main.cpp
	$(CC) $(CFLAGS) $(OBJ) main.cpp -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
