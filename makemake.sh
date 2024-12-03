#!/bin/bash
# Ensure the script is called with the correct number of arguments
if [ "$#" -ne 2 ]; then
	echo "Usage: $0 <source_directory> <program_name>"
	exit 1
fi

# Assign arguments to variables
SRC_DIR=$1
PROGRAM_NAME=$2

# Find all .hpp and .cpp files in the current directory
HDR_FILES=$(find $SRC_DIR -maxdepth 1 -name "*.hpp" -printf "%f \\\\\n\t\t\t")
SRC_FILES=$(find $SRC_DIR -maxdepth 1 -name "*.cpp" -printf "%f \\\\\n\t\t\t")

# Create the Makefile
cat > "$SRC_DIR/Makefile" <<EOF
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	$PROGRAM_NAME

HDR		=	$HDR_FILES

SRC		=	$SRC_FILES

all: \$(NAME)

\$(NAME): \$(SRC) \$(HDR)
	\$(CC) \$(CFLAGS) \$(SRC) -o \$(NAME)

clean:

fclean: clean
	rm -f \$(NAME)

re: fclean all

.PHONY: all clean fclean re
EOF

# Notify the user of the created file
echo "Makefile created for program: $PROGRAM_NAME"

# Create #include list for HDR files
HDR_FILES=$(find $SRC_DIR -maxdepth 1 -name "*.hpp" -printf "#include \"%f\"\\n" | sort)
# Create main.cpp
cat > "$SRC_DIR/main.cpp" <<EOF
$HDR_FILES

int	main(void)
{

}
EOF
