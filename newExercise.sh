#!/bin/bash

# Ensure the script is called with the correct number of arguments
if [ "$#" -lt 2 ]; then
	echo "Usage: $0 <source_directory> <program_name> [<class_name_1> ... <class_name_n>]"
	exit 1
fi

# Assign arguments to variables
SRC_DIR="src"
CLASS_DIR="$SRC_DIR/classes"
PARENT_DIR=$1
DEST_DIR="$PARENT_DIR/$CLASS_DIR"
PROGRAM_NAME=$2
shift 2

# Create required directories
mkdir -p "$DEST_DIR"
mkdir -p "$PARENT_DIR/$SRC_DIR"

# Create CLASS files only in src/classes
for CLASS_NAME in "$@"; do
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
	printf "\e[35mFiles created for Class: \e[36m$CLASS_NAME\e[0m\n"
done

# Create the Makefile
cat > "$PARENT_DIR/Makefile" <<EOF
CC					=	c++
CFLAGS				=	-std=c++98 -Wall -Wextra -Werror -Wshadow

NAME				=	$PROGRAM_NAME

CLASSES_DIR			=	classes
CLASSES_SRC			=	$(find "$PARENT_DIR/$CLASS_DIR" -name "*.cpp" -exec basename {} \; | sort -u | awk '{if (NR == 1) printf "%s", $0; else printf " \\\n\t\t\t\t\t\t%s", $0;}')

SOURCE_DIR			=	src
SOURCE				=	\$(addprefix \$(SOURCE_DIR)/\$(CLASSES_DIR)/, \$(CLASSES_SRC)) \\
						\$(SOURCE_DIR)/main.cpp

OBJECTS_DIR			=	objects
OBJECTS				=	\$(SOURCE:\$(SOURCE_DIR)/%.cpp=\$(OBJECTS_DIR)/%.o)

all: \$(NAME)

\$(OBJECTS_DIR)/%.o: \$(SOURCE_DIR)/%.cpp
	@mkdir -p \$(dir \$@)
	\$(CC) \$(CFLAGS) -I./ -I\$(SOURCE_DIR) -o \$@ -c \$<

\$(NAME): \$(OBJECTS)
	\$(CC) \$(CFLAGS) \$(OBJECTS) -o \$(NAME)

clean:
	@if [ -n "\$(OBJECTS_DIR)" ] && [ "\$(OBJECTS_DIR)" != "/" ] && [ -d "\$(OBJECTS_DIR)" ]; then \\
		rm -rf \$(OBJECTS_DIR); \\
	else \\
		echo "Error: OBJECTS_DIR is undefined or invalid"; \\
	fi

fclean: clean
	rm -f \$(NAME)

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre
EOF

# Notify the user of the created file
echo "Makefile created for program: $PROGRAM_NAME"

# Generate #include list for all .hpp files in src and its subdirectories
INCLUDES=$(find "$PARENT_DIR/$SRC_DIR" -name "*.hpp" | sort | awk -v base="$PARENT_DIR/$SRC_DIR/" '{
	sub(base, "", $0);
	printf "#include \"%s\"\n", $0;
}')

# Create main.cpp
cat > "$PARENT_DIR/$SRC_DIR/main.cpp" <<EOF
# include <iostream>

$INCLUDES

int	main(void)
{
}
EOF

# Notify the user of the created file
echo "main.cpp created with heading:"
echo "$INCLUDES"

# Summary of created files
printf "\n\e[32mAll files created:\e[0m\n"
find "$PARENT_DIR" -type f | sort | while read -r file; do
	filename=$(basename "$file")
	filepath=$(realpath --relative-to="./" "$file")
	case "${filename##*.}" in
		hpp) color="\e[35m" ;; # Purple
		cpp) color="\e[36m" ;; # Cyan
		Makefile) color="\e[31m" ;; # Red
		*) color="\e[37m" ;; # Default
	esac
	printf "${color}+\e[0m %s/${color}%s\e[0m\n" "$(dirname "$filepath")" "$filename"
done
