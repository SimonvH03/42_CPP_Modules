#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::display_contact(void)
{
	std::cout << "    First name: " << this->firstName << '\n';
	std::cout << "     Last name: " << this->lastName << '\n';
	std::cout << "      Nickname: " << this->nickname << '\n';
	std::cout << "  Phone number: " << this->phoneNumber << '\n';
	std::cout << "Darkest secret: " << this->darkestSecret << '\n';
}

void	Contact::setFirstName(std::string first_name)
{
	this->firstName = first_name;
}

void	Contact::setLastName(std::string last_name)
{
	this->lastName = last_name;
}

void	Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	this->phoneNumber = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	this->darkestSecret = darkest_secret;
}

std::string	Contact::getFirstName(void)
{
	return (this->firstName);
}

std::string	Contact::getLastName(void)
{
	return (this->lastName);
}

std::string	Contact::getNickName(void)
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}
