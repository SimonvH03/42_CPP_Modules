#include "ClapTrap.hpp"

const unsigned int	ClapTrap::attackCost = 30;
const unsigned int	ClapTrap::recoverCost = 20;

ClapTrap::ClapTrap()
	:	Name	("ClapTrap")
	,	HP		(10)
	,	Energy	(10)
	,	ATK		(0)
{
#ifdef VERBOSE
	std::cout << "ClapTrap Default Constructor\n";
#endif
}

ClapTrap::ClapTrap(std::string name)
	:	Name	(name)
	,	HP		(10)
	,	Energy	(10)
	,	ATK		(0)
{
#ifdef VERBOSE
	std::cout << "ClapTrap Name Constructor\n";
#endif
}

ClapTrap::ClapTrap(ClapTrap const &original)
	:	Name	(original.Name)
	,	HP		(original.HP)
	,	Energy	(original.Energy)
	,	ATK		(original.ATK)
{
#ifdef VERBOSE
	std::cout << "ClapTrap Copy Constructor\n";
#endif
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &original)
{
#ifdef VERBOSE
	std::cout << "ClapTrap Assignment Operator\n";
#endif

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
#ifdef VERBOSE
	std::cout << "ClapTrap Destructor\n";
#endif
}

void	ClapTrap::attack(std::string const &target)
{
#ifdef VERBOSE
	std::cout << "ClapTrap attack()\n";
#endif

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
#ifdef VERBOSE
	std::cout << "ClapTrap recover()\n";
#endif

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
#ifdef VERBOSE
	std::cout << "ClapTrap takeDamage()\n";
#endif

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

void	ClapTrap::setName(std::string const &name)
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
