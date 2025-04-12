CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

NAME		=	Abstract\ Class

GNL_DIR		=	get_next_line
GNL			=	$(GNL_DIR)/get_next_line.a

CLS_DIR		=	classes
CLS			=	Animal.cpp \
				Brain.cpp \
				Cat.cpp \
				Dog.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp

SRC_DIR		=	src
SRC			=	$(addprefix $(SRC_DIR)/$(CLS_DIR)/, $(CLS)) \
				$(SRC_DIR)/main.cpp

OBJ_DIR		=	objects
OBJ			=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I./ -I$(SRC_DIR) -o $@ -c $<

$(GNL):
	make -C $(GNL_DIR) all -s

$(NAME): $(OBJ) $(GNL)
	$(CXX) $(CXXFLAGS) $(OBJ) $(GNL) -o $(NAME)

clean:
	@if [ -n "$(OBJ_DIR)" ] && [ "$(OBJ_DIR)" != "/" ] && [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
	else \
		echo "Error: OBJ_DIR is undefined or invalid"; \
	fi
	make -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(GNL_DIR)/get_next_line.a

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre
