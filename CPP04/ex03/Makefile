CXX			=	c++
CXXFLAGS	=	-std=c++98 -Wall -Werror -Wextra -Wshadow

NAME		=	Interface

CLASSES_DIR	=	classes
CLASSES		=	AMateria.cpp \
				Character.cpp \
				Cure.cpp \
				Ice.cpp \
				ICharacter.cpp \
				IMateriaSource.cpp \
				MateriaSource.cpp

SRC_DIR		=	src
SRC			=	$(SRC_DIR)/main.cpp \
				$(addprefix $(SRC_DIR)/$(CLASSES_DIR)/, $(CLASSES))

OBJ_DIR		=	obj
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
