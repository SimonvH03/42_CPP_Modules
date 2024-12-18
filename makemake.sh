#!/bin/bash
# Ensure the script is called with the correct number of arguments
if [ "$#" -lt 2 ]; then
	echo "Usage: $0 <source_directory> <program_name> {add_main=0,1}"
	exit 1
fi

# Assign arguments to variables
CLASS_DIR="classes"
PARENT_DIR=$1
PROGRAM_NAME=$2
ADD_MAIN=${3:-0}

# Find all .hpp and .cpp files in the current directory
format_files()
{
	find "$PARENT_DIR/$CLASS_DIR" -maxdepth 1 -name "*.$1" -exec basename {} \; | sort -u | awk '{
		if (NR == 1) printf "$(CLS_DIR)/%s", $0;
		else printf " \\\n\t\t\t$(CLS_DIR)/%s", $0;}'
}

HDR_FILES=$(format_files "hpp")
SRC_FILES=$(format_files "cpp")

# Create the Makefile
cat > "$PARENT_DIR/Makefile" <<EOF
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	$PROGRAM_NAME

CLS_DIR	=	./classes

HDR		=	$HDR_FILES

SRC		=	$SRC_FILES

OBJ_DIR	=	./objects
OBJ		=	\$(SRC:\$(CLS_DIR)/%.cpp=\$(OBJ_DIR)/%.o)

all: \$(NAME)

\$(OBJ_DIR):
	mkdir -p \$(OBJ_DIR)

\$(OBJ_DIR)/%.o: \$(CLS_DIR)/%.cpp \$(OBJ_DIR)
	\$(CC) \$(CFLAGS) -o \$@ -c $<

\$(NAME): \$(OBJ) \$(HDR) main.cpp
	\$(CC) \$(CFLAGS) \$(OBJ) main.cpp -o \$(NAME)

clean:
	rm -f \$(OBJ)

fclean: clean
	rm -f \$(NAME)

re: fclean all

.PHONY: all clean fclean re
EOF

# Notify the user of the created file
echo "Makefile created for program: $PROGRAM_NAME"

# Conditionally create main.cpp if add_main is set to 1
if [ "$ADD_MAIN" -eq 1 ]; then
	# Generate #include list for HDR files
	INCLUDES=$(find "$PARENT_DIR/$CLASS_DIR" -maxdepth 1 -name "*.hpp" -printf "#include \"$CLASS_DIR/%f\"\\n" | sort)

	# Create main.cpp
	cat > "$PARENT_DIR/main.cpp" <<EOF
$INCLUDES
# include <iostream>

int	main(void)
{
}
EOF

	# Notify the user of the created file
	echo "main.cpp created with heading:"
	echo "$INCLUDES"
fi