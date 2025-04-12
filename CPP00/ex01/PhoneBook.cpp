#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_contactIndex = 0;
	_contactCount = 0;
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

void	PhoneBook::addContact(void)
{
	std::string	input;

	std::cout << "[Adding Contact " << _contactIndex % MAXIMUM_CONTACTS + 1 << "]\n";
	if (_contactCount == MAXIMUM_CONTACTS)
		std::cout << "Warning: overwriting oldest contact!\n";
	if (get_nonempty_input("Enter first name: ", &input))
		return ;
	_contacts[_contactIndex % MAXIMUM_CONTACTS].setFirstName(input);
	if (get_nonempty_input("Enter last name: ", &input))
		return ;
	_contacts[_contactIndex % MAXIMUM_CONTACTS].setLastName(input);
	if (get_nonempty_input("Enter nickname: ", &input))
		return ;
	_contacts[_contactIndex % MAXIMUM_CONTACTS].setNickname(input);
	if (get_nonempty_input("Enter phone number: ", &input))
		return ;
	_contacts[_contactIndex % MAXIMUM_CONTACTS].setPhoneNumber(input);
	if (get_nonempty_input("Enter darkest secret: ", &input))
		return ;
	_contacts[_contactIndex % MAXIMUM_CONTACTS].setDarkestSecret(input);
	std::cout << "Contact " << _contactIndex % MAXIMUM_CONTACTS + 1 << " Added Successfully.\n";
	_contactIndex = _contactIndex % MAXIMUM_CONTACTS + 1;
	_contactCount++;
	if (_contactCount > MAXIMUM_CONTACTS)
		_contactCount = MAXIMUM_CONTACTS;
}

void	PhoneBook::searchContact(void)
{
	if (_contactIndex == 0)
	{
		std::cout << "No contacts to display.\n";
		return ;
	}
	displayContactsTable();
	displayIndexedContact();
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

void	PhoneBook::displayContactsTable(void)
{
	std::cout << "     index|first name| last name|  nickname\n";
	std::cout << std::setw(COLUMN_WIDTH)
		<< "index" << "|";
	std::cout << std::setw(COLUMN_WIDTH)
		<< "first name" << "|";
	std::cout << std::setw(COLUMN_WIDTH)
		<< "last name" << "|";
	std::cout << std::setw(COLUMN_WIDTH)
		<< "nickname" << "|";
	for (int i = 0; i < _contactCount; i++)
	{
		std::cout << std::setw(COLUMN_WIDTH)
			<< i + 1 << "|";
		std::cout << std::setw(COLUMN_WIDTH)
			<< truncate_table_entry(_contacts[i].getFirstName(), COLUMN_WIDTH) << "|";
		std::cout << std::setw(COLUMN_WIDTH)
			<< truncate_table_entry(_contacts[i].getLastName(), COLUMN_WIDTH) << "|";
		std::cout << std::setw(COLUMN_WIDTH)
			<< truncate_table_entry(_contacts[i].getNickName(), COLUMN_WIDTH) << '\n';
	}
}

void	PhoneBook::displayIndexedContact(void)
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
	if (index >= 0 && index < _contactCount)
	{
		std::cout << "[Displaying Contact " << index + 1 << "]\n";
		_contacts[index].display_contact();
	}
	else
		std::cout << "Invalid index.\n";
}
