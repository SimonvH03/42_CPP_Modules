#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::display_contact(void)
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << " Last name: " << last_name << std::endl;
	std::cout << "  Nickname: " << nickname << std::endl;
}

void	Contact::set_firstname(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::set_lastname(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string	Contact::get_firstname(void)
{
	return (first_name);
}

std::string	Contact::get_lastname(void)
{
	return (last_name);
}

std::string	Contact::get_nickname(void)
{
	return (nickname);
}
