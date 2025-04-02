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
	std::cout << "> ScavTrap Constructor called for " << name << '\n';
	HP = 100;
	Energy = 50;
	ATK = 20;
	guardState = false;
	guardCost = 20;
}

ScavTrap::ScavTrap(ScavTrap const &original) : ClapTrap(original)
{
	std::cout	<< "> ScavTrap Copy Constructor called on " << original.Name << '\n';
	*this = original;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &original)
{
	std::cout	<< "> ScavTrap Assignment Operator called on " << original.Name << '\n';
	if (this != &original)
	{
		ClapTrap::operator=(original);
		guardState = original.guardState;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "> ScavTrap Destructor called for " << Name << '\n';
}

void	ScavTrap::guardGate()
{
	std::cout << Name;
	guardState = !guardState;
	if (guardState)
	{
		if (Energy < guardCost)
			std::cout << " attemps to Guard, but has insufficient Energy\n";
		else
		{
			Energy -= guardCost;
			std::cout << " is Guarding, incoming damage reduced\n";
		}
	}
	else
		std::cout << " is no longer Guarding\n";
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

std::string	ScavTrap::status() const
{
	std::string	status = ClapTrap::status();

	if (guardState)
		status += " G";
	return (status);
}
