CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	Now\ it\'s\ weird!

CLSDIR	=	./classes

HDR		=	$(CLSDIR)/ClapTrap.hpp \
			$(CLSDIR)/FragTrap.hpp \
			$(CLSDIR)/ScavTrap.hpp \
			$(CLSDIR)/DiamondTrap.hpp

SRC		=	$(CLSDIR)/ClapTrap.cpp \
			$(CLSDIR)/FragTrap.cpp \
			$(CLSDIR)/ScavTrap.cpp \
			$(CLSDIR)/DiamondTrap.cpp \
			main.cpp

OBJDIR	=	./obj
OBJ		=	$(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(HDR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
