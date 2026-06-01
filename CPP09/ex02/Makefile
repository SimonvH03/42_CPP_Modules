MAKEFLAGS	+=	-r -R

CXX			=	c++
CXXFLAGS	=	-MMD -MP -std=c++20
CXXFLAGS	+=	-Wall -Werror -Wextra -Wshadow

NAME		=	PmergeMe

RANDOM_DIR	=	random
RANDOM_BIN	=	$(RANDOM_DIR)/Random

CLASSES_DIR	=	classes
CLASSES		=	MergeInsort.cpp	\
				Timer.cpp		\

SRC_DIR		=	src
SRC			=	$(SRC_DIR)/main.cpp \
				$(addprefix $(SRC_DIR)/$(CLASSES_DIR)/, $(CLASSES))

OBJ_DIR		=	obj
OBJ			=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEP			=	$(OBJ:.o=.d)

all: $(NAME)

$(RANDOM_BIN):
	make -C $(RANDOM_DIR)
	mv $(RANDOM_BIN) .

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I ./ -I $(SRC_DIR) -o $@ -c $<

$(NAME): $(OBJ) $(RANDOM_BIN)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

clean:
	@if [ -n "$(OBJ_DIR)" ] && [ "$(OBJ_DIR)" != "/" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "rm -rf $(OBJ_DIR)"; \
	else \
		echo "Error: OBJ_DIR is undefined or invalid"; \
	fi

fclean: clean
	make -C $(RANDOM_DIR) fclean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
