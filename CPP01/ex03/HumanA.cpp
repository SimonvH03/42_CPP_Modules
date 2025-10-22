#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon &weapon)
	:	Human(name)
	,	_weapon(weapon)
{
#ifdef	VERBOSE
	std::cout << "HumanA Name & Weapon Constructor\n";
#endif
}

HumanA::~HumanA()
{
#ifdef	VERBOSE
	std::cout << "HumanA Destructor\n";
#endif
}

void	HumanA::attack()
const
{
#ifdef	VERBOSE
	std::cout << "HumanA attack()\n";
#endif

	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}
