CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME		=	Polymorphism

CLASSES_DIR	=	classes

HDR			=	$(CLASSES_DIR)/Animal.hpp \
				$(CLASSES_DIR)/Cat.hpp \
				$(CLASSES_DIR)/Dog.hpp \
				$(CLASSES_DIR)/WrongCat.hpp \
				$(CLASSES_DIR)/WrongAnimal.hpp

SRC			=	$(CLASSES_DIR)/Animal.cpp \
				$(CLASSES_DIR)/Cat.cpp \
				$(CLASSES_DIR)/Dog.cpp \
				$(CLASSES_DIR)/WrongCat.cpp \
				$(CLASSES_DIR)/WrongAnimal.cpp

OBJ_DIR		=	objects
OBJ			=	$(SRC:$(CLASSES_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(CLASSES_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(HDR) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJ) main.cpp -o $(NAME)

clean:
	@if [ -n "$(OBJ_DIR)" ] && [ "$(OBJ_DIR)" != "/" ]; then \
		rm -rf $(OBJ_DIR); \
	else \
		echo "Error: OBJ_DIR is undefined or invalid"; \
	fi

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
