#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	command;

	std::cout << "My Awesome PhoneBook" << std::endl
		<< "Please Enter one of the Commands: ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		std::cout << std::endl << "Enter Command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl << "Input error, exiting..." << std::endl;
			return (1);
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			PhoneBook.add_contact();
		else if (command == "SEARCH")
			PhoneBook.search_contact();
		else
			std::cout << "Invalid command." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "exiting..." << std::endl;
			return (1);
		}
	}
	return (0);
}