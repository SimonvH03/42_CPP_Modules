CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME		=	Now\ it\ is\ weird!

CLS_DIR		=	classes

HDR			=	$(CLS_DIR)/ClapTrap.hpp \
				$(CLS_DIR)/DiamondTrap.hpp \
				$(CLS_DIR)/FragTrap.hpp \
				$(CLS_DIR)/ScavTrap.hpp

SRC			=	$(CLS_DIR)/ClapTrap.cpp \
				$(CLS_DIR)/DiamondTrap.cpp \
				$(CLS_DIR)/FragTrap.cpp \
				$(CLS_DIR)/ScavTrap.cpp

OBJ_DIR		=	objects
OBJ			=	$(SRC:$(CLS_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(CLS_DIR)/%.cpp $(CLS_DIR)/%.hpp $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(HDR) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJ) main.cpp -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
