#include "HumanB.hpp"

HumanB::HumanB(std::string const &name)
	:	Human(name)
	,	_weapon(NULL)
{
#ifdef	VERBOSE
	std::cout << "HumanB Name Constructor\n";
#endif
}

HumanB::~HumanB()
{
#ifdef	VERBOSE
	std::cout << "HumanB Destructor\n";
#endif
}

void	HumanB::setWeapon(Weapon *weapon)
{
#ifdef	VERBOSE
	std::cout << "HumanB setWeapon()\n";
#endif

	_weapon = weapon;
}

void	HumanB::attack()
const
{
#ifdef	VERBOSE
	std::cout << "HumanB attack()\n";
#endif

	std::cout << _name << " attacks with their "
		<< ((_weapon != NULL) ? _weapon->getType() : "bare hands") << "\n";
}
