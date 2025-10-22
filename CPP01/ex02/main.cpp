#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << &string << ": The memory address of the string variable\n";
	std::cout << stringPTR << ": The memory address held by stringPTR\n";
	std::cout << &stringREF << ": The memory address held by stringREF\n";

	std::cout << string << ": The value of the string variable\n";
	std::cout << *stringPTR << ": The value pointed to by stringPTR\n";
	std::cout << stringREF << ": The value pointed to by stringREF\n";

	return (0);
}
