#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::string	Jim = "\e[32mJim\e[0m";
	std::string	Bob = "\e[33mBob\e[0m";

	ScavTrap	a(Jim);
	ScavTrap	b(Bob);

	std::cout << "\n\e[35m[ TURN I ]\e[0m\n" << a.status() << '\t' << b.status() << "\n";
	a.attack(b.getName());
	b.takeDamage(a.getATK());

	b.recover(b.getATK());

	std::cout << "\n\e[35m[ TURN II ]\e[0m\n" << a.status() << '\t' << b.status() << "\n";
	a.attack(b.getName());
	b.takeDamage(a.getATK());

	b.guardGate();

	std::cout << "\n\e[35m[ TURN III ]\e[0m\n" << a.status() << '\t' << b.status() << "\n";
	a.attack(b.getName());
	b.takeDamage(a.getATK());

	a.setEnergy(0);
	b.setATK(a.getHP());
	b.setEnergy(1);
	std::cout << "\n\e[31mAdmin intervention:\e[0m ScavTraps modified\n" << a.status() << '\t' << b.status() << "\n";


	b.attack(a.getName());
	a.takeDamage(b.getATK());

	std::cout << "\n\e[35m[ TURN IV ]\e[0m\n" << a.status() << '\t' << b.status() << "\n";
	a.attack(b.getName());
	a.recover(a.getEnergy());

	b.attack(a.getName());
	b.recover(b.getATK());

	std::cout << "\n";
	return (0);
}
