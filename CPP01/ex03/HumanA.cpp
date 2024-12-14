#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
	std::cout<< this->_name << " was Constructed (HumanA)\n";
}

HumanA::~HumanA()
{
	std::cout<< this->_name << " was Destructed (HumanA)\n";
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << '\n';
}
