#include <iostream>

#include "iter.hpp"
#include "iterRef.hpp"

int	negateInt(int &element)
{
	element = -element;
	return (element);
}

int	negatedInt(int const &element)
{
	return (-element);
}

char	lowerChar(char &element)
{
	element = std::tolower(element);
	return (element);
}

char	loweredChar(char const &element)
{
	return (std::tolower(element));
}

std::string	lowerString(std::string &element)
{
	for (size_t i = 0; i < element.length(); ++i)
		lowerChar(element[i]);
	return (element);
}

std::string	loweredString(std::string const &element)
{
	std::string	result;

	for (size_t i = 0; i < element.length(); ++i)
		result += loweredChar(element[i]);
	return (result);
}

int	main(void)
{
	{
		int			intArray[] = {1, 2, 3};
		int const	intArrayConst[] = {42, 69, 420};

		iterTest(intArray, 3, negateInt, "Int");
		iterTest(intArrayConst, 3, negatedInt, "Int const");
		// iterTest(intArrayConst, 3, negateInt, "Int fail");
	}
	{
		char		charArray[] = {'A', 'B', 'C'};
		char const	charArrayConst[] = {'X', 'Y', 'Z'};

		iterTest(charArray, 3, lowerChar, "Char");
		iterTest(charArrayConst, 3, loweredChar, "Char const");
		// iterTest(charArrayConst, 3, lowerChar, "Char fail");
	}
	{
		std::string			stringArray[] = {"Hello", ", ", "World", "!"};
		std::string const	stringArrayConst[] = {"The ", "World ", "Says: ", "HELLO!"};

		iterTest(stringArray, 4, lowerString, "String");
		iterTest(stringArray, 4, loweredString, "String const");
		// iterTest(stringArrayConst, 4, lowerString, "String fail");
	}

	return (0);
}
