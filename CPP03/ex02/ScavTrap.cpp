#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	Name = "";
	HP = 100;
	Energy = 50;
	ATK = 20;
	guardState = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "> ScavTrap Constructor called for " << name << "\n";
	HP = 100;
	Energy = 50;
	ATK = 20;
	guardState = false;
}

ScavTrap::ScavTrap(ScavTrap const &original) : ClapTrap(original)
{
	std::cout	<< "> ScavTrap Copy Constructor called on " << original.Name << "\n";
	guardState = false;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &original)
{
	std::cout	<< "> ScavTrap Assignment Operator called on " << original.Name << "\n";
	if (this != &original)
	{
		ClapTrap::operator=(original);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "> ScavTrap Destructor called for " << Name << "\n";
}

void	ScavTrap::guardGate()
{
	guardState = !guardState;
	if (guardState)
		std::cout << Name << " is Guarding, incoming damage reduced\n";
	else
		std::cout << Name << " is no longer Guarding\n";
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << Name;
	if (!HP || !Energy)
	{
		std::cout << " attempts an Attack on " << target
			<< ", but has insufficient ";
		if (Energy)
			std::cout << "HP";
		else if (HP)
			std::cout << "Energy";
		else
			std::cout << "HP and Energy";
		std::cout << ": No damage done\n";
		return;
	}
	--Energy;
	if (guardState)
		guardGate();
	std::cout << " Attacks " << target << ": " << ATK << " damage dealt\n";
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (guardState)
	{
		ClapTrap::takeDamage(amount / 2);
		guardGate();
	}
	else
		ClapTrap::takeDamage(amount);
}

std::string	ScavTrap::status()
{
	std::string	status = ClapTrap::status();

	if (guardState)
		status += " G";
	return (status);
}
