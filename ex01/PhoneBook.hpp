#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

# define MAXIMUM_CONTACTS 8
# define COLUMN_WIDTH 10

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void		add_contact(void);
		void		search_contact(void);
	private:
		Contact		contacts[8];
		int			contact_count;
		void		display_contacts_table(void);
		void		display_indexed_contact(void);
};

#endif