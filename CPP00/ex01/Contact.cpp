#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::display_contact(void)
{
	std::cout << "    First name: " << firstName << '\n';
	std::cout << "     Last name: " << lastName << '\n';
	std::cout << "      Nickname: " << nickname << '\n';
	std::cout << "  Phone number: " << phoneNumber << '\n';
	std::cout << "Darkest secret: " << darkestSecret << '\n';
}

void	Contact::setFirstName(std::string first_name)
{
	firstName = first_name;
}

void	Contact::setLastName(std::string last_name)
{
	lastName = last_name;
}

void	Contact::setNickname(std::string nickname)
{
	nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	phoneNumber = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	darkestSecret = darkest_secret;
}

std::string	Contact::getFirstName(void)
{
	return (firstName);
}

std::string	Contact::getLastName(void)
{
	return (lastName);
}

std::string	Contact::getNickName(void)
{
	return (nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (phoneNumber);
}

std::string	Contact::getDarkestSecret(void)
{
	return (darkestSecret);
}
