#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class	PhoneBook
{
	public:
		static const std::size_t	MaximumContacts = 8;
	private:
		static const std::size_t	ColumnWidth = 10;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact(void);
		void	searchContact(void);

	private:
		Contact		_contacts[MaximumContacts];
		std::size_t	_contactCount;
		std::size_t	_contactIndex;

		void	displayContactsTable(void) const;
		void	displayIndexedContact(void) const;

		static void	truncateTableEntry(std::string &entry);

		static bool	getValidField(std::string &input, std::string const &field);
		bool	getValidIndex(std::string &input) const;
};

#endif
