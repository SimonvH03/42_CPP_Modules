#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	command;

	std::cout << "My Awesome PhoneBook\n"
		<< "Please Enter one of the Commands: ADD, SEARCH, EXIT\n";
	while (1)
	{
		std::cout << std::endl << "Enter Command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl << "Input error, exiting...\n";
			return (1);
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			PhoneBook.addContact();
		else if (command == "SEARCH")
			PhoneBook.searchContact();
		else
			std::cout << "Invalid command.\n";
		if (std::cin.eof())
		{
			std::cout << "exiting...\n";
			return (1);
		}
	}
	return (0);
}