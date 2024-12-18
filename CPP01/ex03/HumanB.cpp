#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
	std::cout<< this->_name << " was Constructed (HumanB)\n";
}

HumanB::~HumanB()
{
	std::cout<< this->_name << " was Destructed (HumanB)\n";
}

void	HumanB::setWeapon(Weapon *weapon)
{
	this->_weapon = weapon;
}

void	HumanB::attack()
{
	if (_weapon == NULL)
		std::cout << this->_name << " fails to attack for lack of a weapon\n";
	else
		std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << '\n';
}
