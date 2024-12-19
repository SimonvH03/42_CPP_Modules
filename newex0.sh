#!/bin/bash

# Ensure the script is called with the correct number of arguments
if [ "$#" -lt 2 ]; then
	echo "Usage: $0 <source_directory> <program_name> [<class_name_1> ... <class_name_n>]"
	exit 1
fi

# Assign arguments to variables
CLASS_DIR="classes"
PARENT_DIR=$1
DEST_DIR="$PARENT_DIR/$CLASS_DIR"
PROGRAM_NAME=$2
shift
shift

# Create the source directory if it doesn't exist
mkdir -p "$DEST_DIR"

for CLASS_NAME in "${@^}"; do
# Define filenames
HEADER_FILE="$DEST_DIR/$CLASS_NAME.hpp"
SOURCE_FILE="$DEST_DIR/$CLASS_NAME.cpp"

# Create the header file with basic class definition
cat > "$HEADER_FILE" <<EOF
#ifndef ${CLASS_NAME^^}_HPP
# define ${CLASS_NAME^^}_HPP
# include <iostream>

class $CLASS_NAME
{
	private:

	protected:

	public:
		$CLASS_NAME();
		$CLASS_NAME($CLASS_NAME const &original);
		$CLASS_NAME &operator=($CLASS_NAME const &original);
		~$CLASS_NAME();
};

#endif
EOF

# Create the source file with basic class implementation
cat > "$SOURCE_FILE" <<EOF
#include "$CLASS_NAME.hpp"

$CLASS_NAME::$CLASS_NAME()
{
	std::cout << "$CLASS_NAME Default Constructor\n";
}

$CLASS_NAME::$CLASS_NAME($CLASS_NAME const &original)
{
	std::cout << "$CLASS_NAME Copy Constructor\n";
	*this = original;
}

$CLASS_NAME &$CLASS_NAME::operator=($CLASS_NAME const &original)
{
	std::cout << "$CLASS_NAME Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

$CLASS_NAME::~$CLASS_NAME()
{
	std::cout << "$CLASS_NAME Destructor\n";
}
EOF

# Notify the user of the created files
printf "\e[35mfiles \e[36mcreated for Class: \e[0m$CLASS_NAME\n"
done

# Find all .hpp and .cpp files in the current directory
format_files()
{
	find "$DEST_DIR" -maxdepth 1 -name "*.$1" -exec basename {} \; | sort -u | awk '{
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
printf "\n\e[33mMakefile created for program: \e[0m$PROGRAM_NAME\n"

# Generate #include list for HDR files
INCLUDES=$(find "$DEST_DIR" -maxdepth 1 -name "*.hpp" -printf "#include \"$CLASS_DIR/%f\"\\n" | sort)

# Create main.cpp
cat > "$PARENT_DIR/main.cpp" <<EOF
$INCLUDES
# include <iostream>

int	main(void)
{
}
EOF

# Notify the user of the created file
printf "\n\e[36mmain.cpp created with heading:\n\e[0;2m$INCLUDES\e[0m\n"

printf "\n\e[32mAll files created:\e[0m\n"
find "$PARENT_DIR" -type f | sort | while read -r file; do
    # Extract the filename and its relative path
    filename=$(basename "$file")
    filepath=$(realpath --relative-to="./" "$file")

    # Set colors based on file type
    case "${filename##*.}" in
        hpp)
            color="\e[35m" # Purple
            ;;
        cpp)
            color="\e[36m" # Cyan
            ;;
        Makefile)
            color="\e[31m" # Orange/Red
            ;;
        *)
            color="\e[37m" # Default (white/gray)
            ;;
    esac

    # Print the file path with the filename color-coded
    printf "${color}+\e[0m %s/${color}%s\e[0m\n" "$(dirname "$filepath")" "$filename"
done
