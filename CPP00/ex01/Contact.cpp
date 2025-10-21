#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

Contact::Content::Content()
	:	firstName("")
	,	lastName("")
	,	nickname("")
	,	phoneNumber("")
	,	darkestSecret("")
{
}

Contact::Content &Contact::Content::operator=(Contact::Content const &other)
{
	if (this != &other)
	{
		firstName = other.firstName;
		lastName = other.lastName;
		nickname = other.nickname;
		phoneNumber = other.phoneNumber;
		darkestSecret = other.darkestSecret;
	}
	return (*this);
}

void	Contact::setContent(Contact::Content const &content)
{
	_content = content;
}

Contact::Content const	&Contact::getContent()
const
{
	return (_content);
}
