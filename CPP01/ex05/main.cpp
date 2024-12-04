#include "Harl.hpp"
# include <iostream>

int main( void ) {

    std::string input;
    Harl        harl;

    do
    {
        std::cout << "Enter a level: ";
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
