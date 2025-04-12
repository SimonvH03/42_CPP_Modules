#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA constructed: " << _name  << "\n";
}

HumanA::~HumanA()
{
	std::cout << "HumanA destructed: " << _name  << "\n";
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << '\n';
}
