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
			std::cout << "\nInput error, ";
			return (1);
		}
		if ((*input).length() > 0)
			return (0);
		std::cout << "Input cannot be empty.\n";
	}
}

void	PhoneBook::add_contact(void)
{
	std::string	input;

	if (contact_count < MAXIMUM_CONTACTS)
		contact_count++;
	std::cout << "[Adding Contact " << contact_count<< "]\n";
	if (contact_count == MAXIMUM_CONTACTS)
		std::cout << "!Warning: possibly overwriting last contact!\n";
	if (get_nonempty_input("Enter first name: ", &input))
		return ;
	contacts[contact_count - 1].setFirstName(input);
	if (get_nonempty_input("Enter last name: ", &input))
		return ;
	contacts[contact_count - 1].setLastName(input);
	if (get_nonempty_input("Enter nickname: ", &input))
		return ;
	contacts[contact_count - 1].setNickname(input);
	if (get_nonempty_input("Enter phone number: ", &input))
		return ;
	contacts[contact_count - 1].setPhoneNumber(input);
	if (get_nonempty_input("Enter darkest secret: ", &input))
		return ;
	contacts[contact_count - 1].setDarkestSecret(input);
	std::cout << "Contact " << contact_count << " Added Successfully.\n";
}

void	PhoneBook::search_contact(void)
{
	if (contact_count == 0)
	{
		std::cout << "No contacts to display.\n";
		return ;
	}
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
	std::cout << "     index|first name| last name|  nickname\n";
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << std::setw(COLUMN_WIDTH) << i + 1 << "|";
		std::cout << std::setw(COLUMN_WIDTH) << truncate_table_entry(contacts[i].getFirstName(), COLUMN_WIDTH) << "|";
		std::cout << std::setw(COLUMN_WIDTH) << truncate_table_entry(contacts[i].getLastName(), COLUMN_WIDTH) << "|";
		std::cout << std::setw(COLUMN_WIDTH) << truncate_table_entry(contacts[i].getNickName(), COLUMN_WIDTH) << '\n';
	}
}

void	PhoneBook::display_indexed_contact(void)
{
	std::string	input;
	int			index;

	std::cout << "\nEnter an index to display contact information: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << "\nInput error, ";
		return ;
	}
	index = (input.length() == 1) ? input[0] - '1': -1;
	if (index >= 0 && index < contact_count)
	{
		std::cout << "[Displaying Contact " << index + 1 << "]\n";
		contacts[index].display_contact();
	}
	else
		std::cout << "Invalid index.\n";
}
