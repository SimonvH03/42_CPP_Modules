MAKEFLAGS	=	-r -R

CXX			=	c++
CXXFLAGS	=	-MMD -MP -std=c++98
CXXFLAGS	+=	-Wall -Werror -Wextra -Wshadow
# CXXFLAGS	+=	-D VERBOSE

NAME		=	Unnecessary\ violence

INCLUDE_DIRS=	$(SUBJECT_DIR) \
				$(LIB_TF_INC)
INCLUDE		=	$(addprefix -I , $(INCLUDE_DIRS))

TEST_DIR	=	.
TEST_SRC	=	main.cpp

SUBJECT_DIR	=	.
SUBJECT_SRC	=	Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp \
				Human.cpp

SRC			:=	$(addprefix $(TEST_DIR)/, $(TEST_SRC)) \
				$(addprefix $(SUBJECT_DIR)/, $(SUBJECT_SRC))

OBJ_DIR		=	obj
OBJ			:=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP			:=	$(OBJ:.o=.d)

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
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

.PHONY: all clean fclean re
