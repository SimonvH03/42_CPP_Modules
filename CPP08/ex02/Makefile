MAKEFLAGS	=	-r -R

CXX			=	c++
CXXFLAGS	=	-MMD -MP -std=c++20
CXXFLAGS	+=	-Wall -Werror -Wextra -Wshadow
# CXXFLAGS	+=	-D VERBOSE

NAME		=	run

LIB_TF_DIR	=	../../TestFramework
LIB_TF_BIN	:=	$(LIB_TF_DIR)/libTestRunner.a
LIB_TF_INC	:=	$(LIB_TF_DIR)/include

INCLUDE_DIRS=	$(SUBJECT_DIR) \
				$(LIB_TF_INC)
INCLUDE		=	$(addprefix -I , $(INCLUDE_DIRS))

TEST_DIR		=	test
TEST_SRC	=	main.cpp \
				tests.cpp

SUBJECT_DIR	=	subject
SUBJECT_SRC	=	

SRC			:=	$(addprefix $(TEST_DIR)/, $(TEST_SRC)) \
				$(addprefix $(SUBJECT_DIR)/, $(SUBJECT_SRC))

OBJ_DIR		=	obj
OBJ			:=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP			:=	$(OBJ:.o=.d)

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ) $(LIB_TF_BIN)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LIB_TF_BIN) -o $(NAME)

$(LIB_TF_BIN):
	$(MAKE) -C $(LIB_TF_DIR)

-include $(DEP)

clean:
	@if [ -n "$(OBJ_DIR)" ] && [ "$(OBJ_DIR)" != "/" ]; then \
		rm -rf $(OBJ_DIR); echo 'rm -rf $(OBJ_DIR)'; \
	else \
		echo "Warning: OBJ_DIR is undefined"; \
	fi
	$(MAKE) -C $(LIB_TF_DIR) fclean -s

fclean: clean
	rm -f $(NAME)
	rm -f failLog.txt

re: clean all

.PHONY: all clean fclean re
