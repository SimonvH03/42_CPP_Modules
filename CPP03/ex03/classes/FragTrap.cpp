#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	Name = "";
	HP = 100;
	Energy = 50;
	ATK = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "> FragTrap Constructor called for " << name << "\n";
	HP = 100;
	Energy = 100;
	ATK = 30;
}

// derived class assignment operator only called when it adds assignments after base class constructor
FragTrap::FragTrap(FragTrap const &original) : ClapTrap(original)
{
	std::cout	<< "> FragTrap Copy Constructor called on " << original.Name << "\n";
	// *this = original;
}

FragTrap& FragTrap::operator=(FragTrap const &original)
{
	std::cout	<< "> FragTrap Assignment Operator called on " << original.Name << "\n";
	if (this != &original)
	{
		ClapTrap::operator=(original);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "> FragTrap Destructor called for " << Name << "\n";
}

void	FragTrap::highFiveGuys()
{
	std::cout << Name << " is desperate for a high five guys!\n";
}
