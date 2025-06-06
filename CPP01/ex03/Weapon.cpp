#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
	std::cout << "Weapon constructed: " << _type  << "\n";
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructed: " << _type  << "\n";
}

void	Weapon::setType(std::string type)
{
	_type = type;
	std::cout << "Weapon Type set: " << _type  << "\n";
}

std::string	const &Weapon::getType() const
{
	return (_type);
}
