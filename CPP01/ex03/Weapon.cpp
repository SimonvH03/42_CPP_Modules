#include "Weapon.hpp"

Weapon::Weapon(std::string const &type)
	:	_type(type)
{
#ifdef	VERBOSE
	std::cout << "Weapon Type Constructor\n";
#endif
}

Weapon::~Weapon()
{
#ifdef	VERBOSE
	std::cout << "Weapon Destructor\n";
#endif
}

void	Weapon::setType(std::string const &type)
{
#ifdef	VERBOSE
	std::cout << "Weapon setType()\n";
#endif
	_type = type;
}

std::string	const &Weapon::getType()
const
{
	return (_type);
}
