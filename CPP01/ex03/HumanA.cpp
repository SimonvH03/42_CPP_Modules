#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
}

HumanA::~HumanA()
{
	// std::cout << "Destructing HumanA " << this->_name << '\n';
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << '\n';
}
