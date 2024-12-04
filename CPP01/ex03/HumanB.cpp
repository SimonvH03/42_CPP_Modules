#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB()
{
	// std::cout << "Destructing HumanB " << this->_name << '\n';
}

void	HumanB::setWeapon(Weapon weapon)
{
	*this->_weapon = weapon;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << '\n';
}
