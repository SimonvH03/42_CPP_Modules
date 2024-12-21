CC					=	c++
CFLAGS				=	-Wall -Wextra -Werror -std=c++98

NAME				=	Interface

CLASSES_DIR			=	classes
CLASSES_SRC			=	AMateria.cpp \
						Character.cpp \
						Cure.cpp \
						Ice.cpp \
						ICharacter.cpp \
						IMateriaSource.cpp \
						MateriaSource.cpp

SOURCE_DIR			=	src
SOURCE				=	$(SOURCE_DIR)/main.cpp \
						$(addprefix $(SOURCE_DIR)/$(CLASSES_DIR)/, $(CLASSES_SRC))

OBJECTS_DIR			=	objects
OBJECTS				=	$(SOURCE:$(SOURCE_DIR)/%.cpp=$(OBJECTS_DIR)/%.o)

all: $(NAME)

$(OBJECTS_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./ -I$(SOURCE_DIR) -o $@ -c $<

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	@if [ -n "$(OBJECTS_DIR)" ] && [ "$(OBJECTS_DIR)" != "/" ] && [ -d "$(OBJECTS_DIR)" ]; then \
		rm -rf $(OBJECTS_DIR); \
	else \
		echo "Error: OBJECTS_DIR is undefined or invalid"; \
	fi

fclean: clean
	rm -f $(NAME)

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre
