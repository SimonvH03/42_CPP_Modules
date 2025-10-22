#include <iostream>

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	command;

	std::cout << "My Awesome PhoneBook\n"
		<< "Please Enter one of the Commands: ADD, SEARCH, EXIT\n";
	while (true)
	{
		std::cout << "\nEnter Command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nInput error, exiting...\n";
			return (1);
		}
		if (command == "ADD")
			PhoneBook.addContact();
		else if (command == "SEARCH")
			PhoneBook.searchContact();
		else if	(command == "EXIT")
			break ;
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