CXX			=	c++
CXXFLAGS	=	-std=c++98 -Wall -Werror -Wextra -Wshadow

NAME		=	Abstract\ Class

CLASSES_DIR	=	classes
CLASSES		=	Animal.cpp \
				Brain.cpp \
				Cat.cpp \
				Dog.cpp

SRC_DIR		=	src
SRC			=	$(addprefix $(SRC_DIR)/$(CLASSES_DIR)/, $(CLASSES)) \
				$(SRC_DIR)/main.cpp

OBJ_DIR		=	objects
OBJ			=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@if [ -n "$(OBJ_DIR)" ] && [ "$(OBJ_DIR)" != "/" ]; then \
		rm -rf $(OBJ_DIR); \
	else \
		echo "Error: OBJ_DIR is undefined or invalid"; \
	fi

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
