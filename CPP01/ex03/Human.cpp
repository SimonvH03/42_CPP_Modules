#include "Human.hpp"

Human::Human(std::string const &name)
	:	_name(name)
{
#ifdef	VERBOSE
	std::cout << "Human Name Constructor\n";
#endif
}

Human::~Human()
{
#ifdef	VERBOSE
	std::cout << "Human Destructor\n";
#endif
}
