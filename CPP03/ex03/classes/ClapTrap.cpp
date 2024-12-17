#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor called for " << name << '\n';
	Name = name;
	HP = 10;
	Energy = 10;
	ATK = 0;
	attackCost = 30;
	repairCost = 20;
}

ClapTrap::ClapTrap(ClapTrap const &original)
{
	std::cout << "ClapTrap Copy Constructor called on " << original.Name << '\n';
	*this = original;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &original)
{
	std::cout	<< "ClapTrap Assignment Operator called on " << original.Name << '\n';
	if (this != &original)
	{
		Name	= original.Name;
		HP		= original.HP;
		Energy	= original.Energy;
		ATK		= original.ATK;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called for " << Name << '\n';
}

// unsure whether the subject mandates "ClapTrap causes its target to lose <ATK> Health points" means the ClapTrap needs to sniff out another ClapTrap just by name...
//	I would not design it that way, because it means each ClapTrap needs to be aware of the scene it lives in. For that reason I will not implement this feature.
void	ClapTrap::attack(std::string const &target)
{
	std::cout << Name;
	if (!HP || Energy < attackCost)
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
	Energy -= attackCost;
	std::cout << " Attacks " << target << ": " << ATK << " damage dealt\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << Name;
	if (!HP || Energy < repairCost)
	{
		std::cout << " attempts to repair itself, but has insufficient ";
		if (Energy)
			std::cout << "HP";
		else if (HP)
			std::cout << "Energy";
		else
			std::cout << "HP and Energy";
		std::cout << ": No Health points restored\n";
		return;
	}
	Energy -= repairCost;
	HP += amount;
	if (HP < amount)
		std::cout << " attempts to repair itself, but the laws of nature screwed it over real bad: ";
	else
		std::cout << " repairs itself: " << amount << " Health points are restored: ";
	std::cout << HP << " Health points left\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << Name << " takes " << amount << " damage: ";
	if (HP <= amount)
		HP = 0;
	else
		HP -= amount;
	if (HP == 0)
		std::cout << "The Baby F*cking Dies\n";
	else
		std::cout << HP << " Health points left\n";
}

std::string	ClapTrap::status() const
{
	std::ostringstream status;

	status << Name << " \e[2m(" 
		   << getHP() << " HP, " 
		   << getEnergy() << " E, " 
		   << getATK() << " ATK)\e[0m";

	return (status.str());
}

void	ClapTrap::setName(std::string name)
{
	Name = name;
}

void	ClapTrap::setHP(unsigned int hp)
{
	HP = hp;
}

void	ClapTrap::setEnergy(unsigned int energy)
{
	Energy = energy;
}

void	ClapTrap::setATK(unsigned int atk)
{
	ATK = atk;
}

unsigned int ClapTrap::getHP(void) const
{
	return (HP);
}

unsigned int ClapTrap::getEnergy(void) const
{
	return (Energy);
}

unsigned int ClapTrap::getATK(void) const
{
	return (ATK);
}

std::string	ClapTrap::getName(void) const
{
	return (Name);
}
