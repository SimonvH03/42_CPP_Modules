#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class	Contact
{
	public:
		Contact();
		~Contact();
		void		display_contact(void);
		void		set_firstname(std::string first_name);
		void		set_lastname(std::string last_name);
		void		set_nickname(std::string nickname);
		std::string	get_firstname(void);
		std::string	get_lastname(void);
		std::string	get_nickname(void);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
};

#endif