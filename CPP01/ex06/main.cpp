#include "Harl.hpp"
# include <iostream>

int main()
{
	Harl		harl;
	std::string input;

	do
	{
		std::cout << "Enter a level: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Input error, exiting...\n";
			return (1);
		}
		int i = harl.getLevel(input);
		while ((size_t)i < harl.n_lvl)
		{
			std::cout << '\n' << harl.levels[i] << '\n';
			harl.complain(harl.levels[i++]);
		}
	} while (input.compare("exit"));

	return (0);
}
