#include "Harl.hpp"
#include <iostream>

int main(void)
{
	std::string input;
	Harl		harl;

	do
	{
		std::cout << "(DEBUG, INFO, WARNING, ERROR, exit) Enter a level: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Input error, exiting...\n";
			return (1);
		}
		harl.complain(input);
	} while (input.compare("exit"));

	return (0);
}
