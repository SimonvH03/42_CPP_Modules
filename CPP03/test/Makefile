CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	program

CLS_DIR	=	./classes

HDR		=	$(CLS_DIR)/Class1.hpp \
			$(CLS_DIR)/Class2.hpp

SRC		=	$(CLS_DIR)/Class1.cpp \
			$(CLS_DIR)/Class2.cpp

OBJ_DIR	=	./objects
OBJ		=	$(SRC:$(CLS_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(CLS_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ) main.cpp
	$(CC) $(CFLAGS) $(OBJ) main.cpp -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
