CXX			=	c++
CXXFLAGS	=	-std=c++11 -Wall -Werror -Wextra -Wshadow

NAME		=	Span

SRC_DIR		=	.
SRC			=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Span.cpp

OBJ_DIR		=	obj
OBJ			=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I ./ -I $(SRC_DIR) -o $@ -c $<

$(NAME): $(OBJ) Span.hpp
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
