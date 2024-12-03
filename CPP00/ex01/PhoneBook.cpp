#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_count = 0;
}

PhoneBook::~PhoneBook()
{
}

static	int	get_nonempty_input(std::string prompt, std::string *input)
{
	while (1)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, *input))
		{
			std::cout << std::endl << "Input error, ";
			return (1);
		}
		if ((*input).length() > 0)
			return (0);
		std::cout << "Input cannot be empty." << std::endl;
	}
}

void	PhoneBook::add_contact(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;

	if (contact_count < MAXIMUM_CONTACTS)
		contact_count++;
	std::cout << "Adding Contact " << contact_count<< std::endl;
	if (contact_count == MAXIMUM_CONTACTS)
		std::cout << "!Warning: possibly overwriting last contact." << std::endl;
	if (get_nonempty_input("Enter first name: ", &first_name))
		return ;
	contacts[contact_count - 1].set_firstname(first_name);
	if (get_nonempty_input("Enter last name: ", &last_name))
		return ;
	contacts[contact_count - 1].set_lastname(last_name);
	if (get_nonempty_input("Enter nickname: ", &nickname))
		return ;
	contacts[contact_count - 1].set_nickname(nickname);
	std::cout << "Contact " << contact_count << " Added Successfully." << std::endl;
}

void	PhoneBook::search_contact(void)
{
	display_contacts_table();
	display_indexed_contact();
}

static std::string	truncate_table_entry(std::string input, size_t size)
{
	if (input.length() > size)
	{
		input.replace(size - 1, 1, ".");
		input.resize(size);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '\t')
			input[i] = '_';
	}
	return (input);
}

void	PhoneBook::display_contacts_table(void)
{
	if (contact_count == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << std::setw(COLUMN_WIDTH) << i + 1 << "|";
		std::cout << std::setw(COLUMN_WIDTH) << truncate_table_entry(contacts[i].get_firstname(), COLUMN_WIDTH) << "|";
		std::cout << std::setw(COLUMN_WIDTH) << truncate_table_entry(contacts[i].get_lastname(), COLUMN_WIDTH) << "|";
		std::cout << std::setw(COLUMN_WIDTH) << truncate_table_entry(contacts[i].get_nickname(), COLUMN_WIDTH) << std::endl;
	}
}

void	PhoneBook::display_indexed_contact(void)
{
	std::string	input;
	int			index;

	std::cout << std::endl << "Enter an index to display contact information: ";
	if (!std::getline(std::cin, input))
		{
			std::cout <<std::endl << "Input error, ";
			return ;
		}
	index = (input.length() == 1) ? input[0] - '1': -1;
	if (index >= 0 && index < contact_count)
	{
		std::cout << "Displaying: " << index + 1 << std::endl;
		contacts[index].display_contact();
	}
	else
		std::cout << "Invalid index." << std::endl;
}
