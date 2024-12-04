#!/bin/bash
# Ensure the script is called with the correct number of arguments
if [ "$#" -lt 2 ]; then
	echo "Usage: $0 <source_directory> <program_name> {add_main=0,1}"
	exit 1
fi

# Assign arguments to variables
SRC_DIR=$1
PROGRAM_NAME=$2
ADD_MAIN=${3:-0}

# Find all .hpp and .cpp files in the current directory
format_files()
{
	find "$SRC_DIR" -maxdepth 1 -name "*.$1" -exec basename {} \; | sort -u | awk '{
		if (NR == 1) printf "%s", $0;
		else printf " \\\n\t\t\t%s", $0;}'
}

HDR_FILES=$(format_files "hpp")
SRC_FILES=$(format_files "cpp")

# Create the Makefile
cat > "$SRC_DIR/Makefile" <<EOF
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	$PROGRAM_NAME

HDR		=	$HDR_FILES

SRC		=	$SRC_FILES \
			main.cpp

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

# Conditionally create main.cpp if add_main is set to 1
if [ "$ADD_MAIN" -eq 1 ]; then
	# Generate #include list for HDR files
	INCLUDES=$(find "$SRC_DIR" -maxdepth 1 -name "*.hpp" -printf "#include \"%f\"\\n" | sort)

	# Create main.cpp
	cat > "$SRC_DIR/main.cpp" <<EOF
$INCLUDES
# include <iostream>

int	main(void)
{
}
EOF

	# Notify the user of the created file
	echo "main.cpp created #including headers: $(find "$SRC_DIR" -maxdepth 1 -name "*.hpp" -printf "%f " | sort)"
fi