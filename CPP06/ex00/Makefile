CXX			=	c++
CXXFLAGS	=	-std=c++11 -Wall -Werror -Wextra -Wshadow

NAME		=	convert

CLASSES_DIR	=	classes
CLASSES		=	ScalarConverter.cpp

SRC_DIR		=	src
SRC			=	$(SRC_DIR)/main.cpp \
				$(addprefix $(SRC_DIR)/$(CLASSES_DIR)/, $(CLASSES))

OBJ_DIR		=	obj
OBJ			=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I ./ -I $(SRC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@if [ -n "$(OBJ_DIR)" ] && [ "$(OBJ_DIR)" != "/" ] && [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
	else \
		echo "Error: OBJ_DIR is undefined or invalid"; \
	fi

fclean: clean
	rm -f $(NAME)

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre
