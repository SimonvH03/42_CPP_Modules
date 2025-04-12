#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
	std::cout<< _name << " was Constructed (HumanB)\n";
}

HumanB::~HumanB()
{
	std::cout<< _name << " was Destructed (HumanB)\n";
}

void	HumanB::setWeapon(Weapon *weapon)
{
	_weapon = weapon;
}

void	HumanB::attack()
{
	if (_weapon == NULL)
		std::cout << _name << " fails to attack for lack of a weapon\n";
	else
		std::cout << _name << " attacks with their " << (*_weapon).getType() << '\n';
}
