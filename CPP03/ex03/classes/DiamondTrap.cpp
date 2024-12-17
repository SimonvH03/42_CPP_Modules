#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << ">> Diamond Constructor called for " << name << " (" << ClapTrap::Name << ")\n";
	Name	= name;
	HP		= FragTrap::HP;
	Energy	= ScavTrap::Energy;
	ATK		= FragTrap::ATK;
}

DiamondTrap::DiamondTrap(DiamondTrap const &original) : ClapTrap(original), ScavTrap(original), FragTrap(original)
{
	std::cout << ">> Diamond Copy Constructor called on " << original.Name << '\n';
	*this = original;
}

// FragTrap does not add any mebers to the base class
DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &original)
{
	std::cout << ">> Diamond Assignment Operator called on " << original.Name << '\n';
	if (this == &original)
		return (*this);
	ClapTrap::operator=(original);
	ScavTrap::operator=(original);
	// FragTrap::operator=(original);
	Name = original.Name;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << ">> Diamond Destructor called for " << Name << " (" << ClapTrap::Name << ")\n";
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << Name << ", formally known as " << ClapTrap::Name << '\n';
}
