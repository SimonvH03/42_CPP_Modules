#!/bin/bash

# Ensure the script is called with the correct number of arguments
if [ "$#" -lt 2 ]; then
	echo "Usage: $0 <source_directory> <class_name_1> [<class_name_2> ... <class_name_n>]"
	exit 1
fi

# Assign arguments to variables
DEST_DIR=$1
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