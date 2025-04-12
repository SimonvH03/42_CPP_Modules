#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::display_contact(void)
{
	std::cout << "    First name: " << _firstName << '\n';
	std::cout << "     Last name: " << _lastName << '\n';
	std::cout << "      Nickname: " << _nickname << '\n';
	std::cout << "  Phone number: " << _phoneNumber << '\n';
	std::cout << "Darkest secret: " << _darkestSecret << '\n';
}

void	Contact::setFirstName(std::string first_name)
{
	_firstName = first_name;
}

void	Contact::setLastName(std::string last_name)
{
	_lastName = last_name;
}

void	Contact::setNickname(std::string nickname)
{
	nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	_phoneNumber = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	_darkestSecret = darkest_secret;
}

std::string	Contact::getFirstName(void)
{
	return (_firstName);
}

std::string	Contact::getLastName(void)
{
	return (_lastName);
}

std::string	Contact::getNickName(void)
{
	return (_nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret(void)
{
	return (_darkestSecret);
}
