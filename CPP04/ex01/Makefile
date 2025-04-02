CC					=	c++
CFLAGS				=	-Wall -Werror -Wextra -std=c++98

NAME				=	I\ don\'t\ want\ to\ set\ the\ world\ on\ fire

GET_NEXT_LINE_DIR	=	get_next_line
GET_NEXT_LINE		=	$(GET_NEXT_LINE_DIR)/get_next_line.a

CLASSES_DIR			=	classes
CLASSES_SRC			=	Animal.cpp \
						Brain.cpp \
						Cat.cpp \
						Dog.cpp \
						WrongCat.cpp \
						WrongAnimal.cpp

SOURCE_DIR			=	src
SOURCE				=	$(addprefix $(SOURCE_DIR)/$(CLASSES_DIR)/, $(CLASSES_SRC)) \
						$(SOURCE_DIR)/main.cpp

OBJECTS_DIR			=	objects
OBJECTS				=	$(SOURCE:$(SOURCE_DIR)/%.cpp=$(OBJECTS_DIR)/%.o)

all: $(NAME)

$(OBJECTS_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(GET_NEXT_LINE):
	make -C $(GET_NEXT_LINE_DIR) all -s

$(NAME): $(OBJECTS) $(GET_NEXT_LINE)
	$(CC) $(CFLAGS) $(OBJECTS) $(GET_NEXT_LINE) -o $(NAME)
#	@echo relinking: File $$\(NAME\) \( = $(NAME)\) does not exist.

clean:
	@if [ -n "$(OBJECTS_DIR)" ] && [ "$(OBJECTS_DIR)" != "/" ] && [ -d "$(OBJECTS_DIR)" ]; then \
		rm -rf $(OBJECTS_DIR); \
	else \
		echo "Error: OBJECTS_DIR is undefined or invalid"; \
	fi
	make -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(GET_NEXT_LINE_DIR)/get_next_line.a

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre
