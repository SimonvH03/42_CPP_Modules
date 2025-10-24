#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:	Name		("")
	,	HP			(10)
	,	Energy		(10)
	,	ATK			(0)
	,	attackCost	(30)
	,	recoverCost	(20)
{
	std::cout << "ClapTrap Default Constructor\n";
}

ClapTrap::ClapTrap(std::string name)
	:	Name		(name)
	,	HP			(10)
	,	Energy		(10)
	,	ATK			(0)
	,	attackCost	(30)
	,	recoverCost	(20)
{
	std::cout << "ClapTrap Name Constructor\n";
}

ClapTrap::ClapTrap(ClapTrap const &original)
	:	Name		(original.Name)
	,	HP			(original.HP)
	,	Energy		(original.Energy)
	,	ATK			(original.ATK)
	,	attackCost	(original.attackCost)
	,	recoverCost	(original.recoverCost)
{
	std::cout << "ClapTrap Copy Constructor\n";
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &original)
{
	std::cout << "ClapTrap Assignment Operator\n";

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
	std::cout << "ClapTrap Destructor\n";
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap attack()\n";

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

void	ClapTrap::recover(unsigned int amount)
{
	std::cout << "ClapTrap recover()\n";

	std::cout << Name;
	if (!HP || Energy < recoverCost)
	{
		std::cout << " attempts to recover, but has insufficient ";
		if (Energy)
			std::cout << "HP";
		else if (HP)
			std::cout << "Energy";
		else
			std::cout << "HP and Energy";
		std::cout << ": No Health points restored\n";
		return;
	}
	Energy -= recoverCost;
	HP += amount;
	if (HP < amount)
		std::cout << " attempts to recover, but the laws of nature screwed it over real bad: ";
	else
		std::cout << " repairs itself: " << amount << " Health points are restored: "
			<< HP << " Health points left\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap takeDamage()\n";

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

unsigned int ClapTrap::getHP(void)
const
{
	return (HP);
}

unsigned int ClapTrap::getEnergy(void)
const
{
	return (Energy);
}

unsigned int ClapTrap::getATK(void)
const
{
	return (ATK);
}

std::string	ClapTrap::getName(void)
const
{
	return (Name);
}

std::ostream	&operator<<(std::ostream &os, ClapTrap const &claptrap)
{
	os	<< claptrap.getName() << " \e[2m("
		<< claptrap.getHP() << " HP, "
		<< claptrap.getEnergy() << " E, "
		<< claptrap.getATK() << " ATK)\e[0m";
	return (os);
}
