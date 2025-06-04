CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME		=	Now\ it\ is\ weird!

CLASSES_DIR	=	classes

HDR			=	$(CLASSES_DIR)/ClapTrap.hpp \
				$(CLASSES_DIR)/DiamondTrap.hpp \
				$(CLASSES_DIR)/FragTrap.hpp \
				$(CLASSES_DIR)/ScavTrap.hpp

SRC			=	$(CLASSES_DIR)/ClapTrap.cpp \
				$(CLASSES_DIR)/DiamondTrap.cpp \
				$(CLASSES_DIR)/FragTrap.cpp \
				$(CLASSES_DIR)/ScavTrap.cpp

OBJ_DIR		=	objects
OBJ			=	$(SRC:$(CLASSES_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(CLASSES_DIR)/%.cpp $(CLASSES_DIR)/%.hpp $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(HDR) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJ) main.cpp -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
