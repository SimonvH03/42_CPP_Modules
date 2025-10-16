MAKEFLAGS	=	-r -R

CXX			=	c++
CXXFLAGS	=	-std=c++11
CXXFLAGS	+=	-MMD -MP
CXXFLAGS	+=	-Wall -Werror -Wextra -Wshadow

NAME		=	Easy

INCLUDE_DIRS=	$(SRC_DIR)
INCLUDE		=	$(addprefix -I , $(INCLUDE_DIRS))

SRC_DIR		=	.
SRC			=	main.cpp

SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR		=	obj
OBJ			:=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEP			:=	$(OBJ:.o=.d)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

clean:
	@if [ -n "$(OBJ_DIR)" ] && [ "$(OBJ_DIR)" != "/" ]; then \
		rm -rf $(OBJ_DIR); echo 'rm -rf $(OBJ_DIR)'; \
	else \
		echo "Warning: OBJ_DIR is undefined"; \
	fi

fclean: clean
	rm -f $(NAME)

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre
