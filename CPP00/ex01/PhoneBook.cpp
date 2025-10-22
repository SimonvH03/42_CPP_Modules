#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	:	_contactCount(0)
	,	_contactIndex(0)
{
#ifdef	VERBOSE
	std::cout << "PhoneBook Default Constructor\n";
#endif
}

PhoneBook::~PhoneBook()
{
#ifdef	VERBOSE
	std::cout << "PhoneBook Destructor\n";
#endif
}

bool	PhoneBook::getValidField(std::string &input, std::string const &field)
{
	while (true)
	{
		std::cout << "Enter " << field << ": ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nInput error, ";
			return (1);
		}
		if (input.length() == 0)
			std::cout << "Field can not be empty.\n";
		else break;
	}
	return (0);
}

void	PhoneBook::addContact()
{
#ifdef	VERBOSE
	std::cout << "PhoneBook addContact()\n";
#endif

	std::string			input;
	Contact::Content	content;

	std::cout << "[ Adding Contact " << _contactIndex + 1 << " ]\n";

	if (_contactCount == MaximumContacts)
		std::cout << "Warning: overwriting oldest contact!\n";

	if (getValidField(input, "first name"))		return ;
	content.firstName = input;
	if (getValidField(input, "last name"))		return ;
	content.lastName = input;
	if (getValidField(input, "nickname"))		return ;
	content.nickname = input;
	if (getValidField(input, "phone number"))	return ;
	content.phoneNumber = input;
	if (getValidField(input, "darkest secret"))	return ;
	content.darkestSecret = input;

	_contacts[_contactIndex].setContent(content);

	std::cout << "Contact " << _contactIndex + 1 << " Added Successfully.\n";

	++_contactIndex;
	_contactIndex %= MaximumContacts;
	++_contactCount;
	if (_contactCount > MaximumContacts)
		_contactCount = MaximumContacts;
}

void	PhoneBook::searchContact()
{
#ifdef	VERBOSE
	std::cout << "PhoneBook searchContact()\n";
#endif

	if (_contactCount == 0)	
	{
		std::cout << "No contacts to display.\n";
		return ;
	}
	displayContactsTable();
	displayIndexedContact();
}

void	PhoneBook::displayContactsTable()
const
{
	Contact::Content	content;

	std::cout << "[ Displaying All Contacts (" << _contactCount << ") ]\n";

	std::cout	<< std::setw(ColumnWidth) << std::left << "index" << "|"
				<< std::setw(ColumnWidth) << std::left << "first name" << "|"
				<< std::setw(ColumnWidth) << std::left << "last name" << "|"
				<< std::setw(ColumnWidth) << std::left << "nickname" << "|\n";

	for (std::size_t i = 0; i < _contactCount; ++i)
	{
		content = _contacts[i].getContent();
		truncateTableEntry(content.firstName);
		truncateTableEntry(content.lastName);
		truncateTableEntry(content.nickname);
		std::cout	<< std::setw(ColumnWidth) << std::left << i + 1 << "|"
					<< std::setw(ColumnWidth) << std::left << content.firstName << "|"
					<< std::setw(ColumnWidth) << std::left << content.lastName << "|"
					<< std::setw(ColumnWidth) << std::left << content.nickname << "|\n";
	}
}

void	PhoneBook::displayIndexedContact()
const
{
	std::string			input;
	std::size_t			index;
	Contact::Content	content;

	std::cout << "\n";
	if (getValidIndex(input))	return ;
	index = input[0] - '1';
	std::cout << "[ Displaying Contact " << index + 1 << " ]\n";
	content = _contacts[index].getContent();
	std::cout	<< "    First name: " << content.firstName << "\n"
				<< "     Last name: " << content.lastName << "\n"
				<< "      Nickname: " << content.nickname << "\n"
				<< "  Phone number: " << content.phoneNumber << "\n"
				<< "Darkest secret: " << content.darkestSecret << "\n";
}

bool	PhoneBook::getValidIndex(std::string &input)
const
{
	while (true)
	{
		std::cout << "Enter an index to display contact information: ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nInput error, ";
			return (1);
		}
		if (!(input.length() == 1 &&	std::isdigit(input[0])
			&&	static_cast<size_t>(input[0] - '1') < _contactCount))
			std::cout << "Index does not exist\n";
		else break;
	}
	return (0);
}

void	PhoneBook::truncateTableEntry(std::string &entry)
{
	if (entry.length() > ColumnWidth)
	{
		entry.replace(ColumnWidth - 1, 1, ".");
		entry.resize(ColumnWidth);
	}
	for (size_t i = 0; i < entry.length(); ++i)
	{
		if (entry[i] == '\t')
			entry[i] = '_';
	}
}
