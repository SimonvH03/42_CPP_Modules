#include "Contact.hpp"

Contact::Contact()
{
#ifdef	VERBOSE
	std::cout << "Contact Default Constructor\n";
#endif
}

Contact::~Contact()
{
#ifdef	VERBOSE
	std::cout << "Contact Destructor\n";
#endif
}

Contact::Content::Content()
	:	firstName("")
	,	lastName("")
	,	nickname("")
	,	phoneNumber("")
	,	darkestSecret("")
{
#ifdef	VERBOSE
	std::cout << "Contact::Content Default Constructor\n";
#endif
}

Contact::Content::~Content()
{
#ifdef	VERBOSE
	std::cout << "Contact::Content Destructor\n";
#endif
}

Contact::Content &Contact::Content::operator=(Contact::Content const &other)
{
#ifdef	VERBOSE
	std::cout << "Contact::Content Assignment Operator\n";
#endif

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
#ifdef	VERBOSE
	std::cout << "Contact setContent()\n";
#endif

	_content = content;
}

Contact::Content const	&Contact::getContent()
const
{
	return (_content);
}
