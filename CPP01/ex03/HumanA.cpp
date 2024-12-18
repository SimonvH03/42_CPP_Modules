#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout<< this->_name << " was Constructed (HumanA)\n";
}

HumanA::~HumanA()
{
	std::cout<< this->_name << " was Destructed (HumanA)\n";
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << _weapon.getType() << '\n';
}
