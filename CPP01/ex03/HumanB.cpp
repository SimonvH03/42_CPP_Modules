#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	std::cout<< this->_name << " was Constructed (HumanB)\n";
}

HumanB::~HumanB()
{
	std::cout<< this->_name << " was Destructed (HumanB)\n";
}

void	HumanB::setWeapon(Weapon weapon)
{
	*this->_weapon = weapon;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << '\n';
}
