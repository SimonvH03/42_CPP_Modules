MAKEFLAGS	=	-r -R

CXX			=	c++
CXXFLAGS	=	-std=c++20
CXXFLAGS	+=	-MMD -MP
CXXFLAGS	+=	-Wall -Werror -Wextra -Wshadow
# CXXFLAGS	+=	-D VERBOSE

NAME		=	libTestRunner.a

INCLUDE_DIRS=	./include \
				$(SRC_DIR)
INCLUDE		=	$(addprefix -I , $(INCLUDE_DIRS))

SRC_DIR		=	src
SRC			=	TestCase.cpp \
				TestRunner.cpp

SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR		=	obj
OBJ			:=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEP			:=	$(OBJ:.o=.d)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

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

.PHONY: all clean fclean re
