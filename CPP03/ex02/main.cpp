#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::string	Jim = "\e[32mJim\e[0m";
	std::string	Bob = "\e[33mBob\e[0m";

	ScavTrap	a(Jim);
	FragTrap	b(Bob);

	std::cout << "\nTestcopy: bopy(Bob): \n";
	FragTrap	bopy(Bob);
	std::cout << bopy.status() << "\n";

	std::cout << "\n\e[35m[ TURN I ]\e[0m\n" << a.status() << '\t' << b.status() << '\t' << bopy.status() << "\n";
	a.attack(b.getName());
	b.takeDamage(a.getATK());

	b.recover(b.getATK());

	std::cout << "\n\e[35m[ TURN II ]\e[0m\n" << a.status() << '\t' << b.status() << "\n";
	a.attack(b.getName());
	b.takeDamage(a.getATK());

	b.highFiveGuys();

	a.setEnergy(0);
	b.setATK(a.getHP() * 2);
	b.setEnergy(1);
	std::cout << "\n\e[31mAdmin intervention:\e[0m Bob high fived\n" << a.status() << '\t' << b.status() << "\n";

	a.guardGate();

	b.attack(a.getName());
	a.takeDamage(b.getATK());

	std::cout << "\n\e[35m[ TURN III ]\e[0m\n" << a.status() << '\t' << b.status() << "\n";
	a.attack(b.getName());
	a.recover(a.getEnergy());

	b.attack(a.getName());
	b.recover(b.getATK());

	std::cout << "\n";
	return (0);
}
