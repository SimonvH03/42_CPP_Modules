MAKEFLAGS	=	-r -R

CXX			=	c++
CXXFLAGS	=	-std=c++20
CXXFLAGS	+=	-MMD -MP
CXXFLAGS	+=	-Wall -Werror -Wextra -Wshadow
# CXXFLAGS	+=	-D VERBOSE

NAME		=	SpanTesting

INCLUDE_DIRS=	$(SRC_DIR) \
				$(TEST_DIR) \
				$(SUBJECT_DIR)
INCLUDE		=	$(addprefix -I , $(INCLUDE_DIRS))

SRC_DIR		=	src
MAIN_SRC	=	main.cpp \
				tests.cpp

TEST_DIR	=	$(SRC_DIR)/test
TEST_SRC	=	TestCase.cpp \
				TestRegistrar.cpp \
				TestRunner.cpp

SUBJECT_DIR	=	$(SRC_DIR)/subject
SUBJECT_SRC	=	Span.cpp

SRC			:=	$(addprefix $(SRC_DIR)/, $(MAIN_SRC)) \
				$(addprefix $(TEST_DIR)/, $(TEST_SRC)) \
				$(addprefix $(SUBJECT_DIR)/, $(SUBJECT_SRC))

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
