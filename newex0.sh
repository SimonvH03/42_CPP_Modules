#!/bin/bash

# Ensure the script is called with the correct number of arguments
if [ "$#" -lt 2 ]; then
	echo "Usage: $0 <source_directory> <program_name> [<class_name_1> ... <class_name_n>]"
	exit 1
fi

# Assign arguments to variables
DEST_DIR=$1
PROGRAM_NAME=$2
shift

# Create the source directory if it doesn't exist
mkdir -p "$DEST_DIR"

for CLASS_NAME in "$@"; do
# Define filenames
HEADER_FILE="$DEST_DIR/$CLASS_NAME.hpp"
SOURCE_FILE="$DEST_DIR/$CLASS_NAME.cpp"

# Create the header file with basic class definition
cat > "$HEADER_FILE" <<EOF
#ifndef ${CLASS_NAME^^}_HPP
# define ${CLASS_NAME^^}_HPP

class $CLASS_NAME
{
	public:
		$CLASS_NAME();
		~$CLASS_NAME();
	private:

};

#endif
EOF

# Create the source file with basic class implementation
cat > "$SOURCE_FILE" <<EOF
#include "$CLASS_NAME.hpp"

$CLASS_NAME::$CLASS_NAME()
{
}

$CLASS_NAME::~$CLASS_NAME()
{
}
EOF

# Notify the user of the created files
echo "Created files:"
echo " - $HEADER_FILE"
echo " - $SOURCE_FILE"
done

# Find all .hpp and .cpp files in the current directory
format_files()
{
	find "$DEST_DIR" -maxdepth 1 -name "*.$1" -exec basename {} \; | sort -u | awk '{
		if (NR == 1) printf "%s", $0;
		else printf " \\\n\t\t\t%s", $0;}'
}

HDR_FILES=$(format_files "hpp")
SRC_FILES=$(format_files "cpp")

# Create the Makefile
cat > "$DEST_DIR/Makefile" <<EOF
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

# Generate #include list for HDR files
INCLUDES=$(find "$DEST_DIR" -maxdepth 1 -name "*.hpp" -printf "#include \"%f\"\\n" | sort)

# Create main.cpp
cat > "$DEST_DIR/main.cpp" <<EOF
$INCLUDES

int	main(void)
{
}
EOF

# Notify the user of the created file
echo "main.cpp created #including headers: $(find "$DEST_DIR" -maxdepth 1 -name "*.hpp" -printf "%f " | sort)"
