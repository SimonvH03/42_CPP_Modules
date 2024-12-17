#include "ClapTrap.hpp"
# include <iostream>

int	main(void)
{
	ClapTrap	a("Jim");
	ClapTrap	b("Bob");

	a.setATK(3);
	b.setATK(a.getHP());

	std::cout << '\n';
	a.status();
	b.status();
	std::cout << '\n';

	a.attack(b.getName());
	b.takeDamage(a.getATK());

	b.beRepaired(a.getATK());

	a.attack(b.getName());
	b.takeDamage(a.getATK());

	std::cout << '\n';
	a.status();
	b.status();
	std::cout << '\n';

	b.attack(a.getName());
	a.takeDamage(b.getATK());

	a.beRepaired(10);
	a.attack(b.getName());

	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.takeDamage(b.getHP());
	b.beRepaired(1);
	b.attack(a.getName());

	std::cout << '\n';
	return (0);
}
