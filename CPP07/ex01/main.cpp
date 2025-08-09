#include <iostream>

#include "iter.hpp"

void	negateInt(int &element)
{
	element = -element;
	std::cout << element;
}

void	negateIntConst(int const &element)
{
	std::cout << -element;
}

void	upperChar(char &element)
{
	element = std::toupper(element);
	std::cout << element;
}

void	lowerCharConst(char const &element)
{
	std::cout << static_cast<char>(std::tolower(element));
}

void	upperString(std::string &element)
{
	for (size_t i = 0; i < element.length(); ++i)
		upperChar(element[i]);
}

void	lowerStringConst(std::string const &element)
{
	for (size_t i = 0; i < element.length(); ++i)
		lowerCharConst(element[i]);
}

int	main(void)
{
	{
		int			intArray[] = {1, 2, 3};
		int const	intArrayConst[] = {42, 69, 420};

		iter(intArray, 3, negateInt);
		std::cout << '\n';
		iter(intArray, 3, negateIntConst);
		std::cout << '\n';
		// iter(intArrayConst, 3, negateInt);
		iter(intArrayConst, 3, negateIntConst);
		std::cout << '\n';
	}
	{
		char		charArray[] = {'a', 'b', 'c'};
		char const	charArrayConst[] = {'X', 'Y', 'Z'};

		iter(charArray, 3, upperChar);
		std::cout << '\n';
		iter(charArray, 3, lowerCharConst);
		std::cout << '\n';
		// iter(charArrayConst, 3, upperChar);
		iter(charArrayConst, 3, lowerCharConst);
		std::cout << '\n';
	}
	{
		std::string			stringArray[] = {"Hello", ", ", "World", "!"};
		std::string const	stringArrayConst[] = {"The ", "World ", "Says: ", "HELLO!"};


		iter(stringArray, 4, upperString);
		std::cout << '\n';
		iter(stringArray, 4, lowerStringConst);
		std::cout << '\n';
		// iter(stringArrayConst, 4, upperString);
		iter(stringArrayConst, 4, lowerStringConst);
		std::cout << '\n';
	}
	return (0);
}
