#include "classes/ClapTrap.hpp"
#include "classes/DiamondTrap.hpp"
#include "classes/FragTrap.hpp"
#include "classes/ScavTrap.hpp"
# include <iostream>

void	nl()
{
	std::cout << '\n';
}

int	main(void)
{
	std::string	Jim = "\e[32mJim\e[0m";
	std::string	Bob = "\e[33mBob\e[0m";
	std::string	Zac = "\e[34mZac\e[0m";

	ScavTrap	a(Jim);
	FragTrap	b(Bob);
	DiamondTrap	c(Zac);

	std::cout << "\nTesting Copies...\n";
	ScavTrap	aopy(a);
	FragTrap	bopy(b);
	DiamondTrap	copy(c);

	std::cout << '\n' << a.status() << '\n' << b.status() << '\n' << c.status() << "\n\n";
	std::cout << '\n' << aopy.status() << '\n' << bopy.status() << '\n' << copy.status() << "\n\n";
	copy.whoAmI();

	nl();
	c.whoAmI();
	nl();
	std::cout << "\e[35m[ TURN I ]\e[0m\n" << a.status() << '\n' << b.status() << '\n' << c.status() << "\n\n";
	a.attack(b.getName());
	b.takeDamage(a.getATK());
	nl();
	b.beRepaired(b.getATK());
	nl();
	c.attack(b.getName());
	b.takeDamage(c.getATK());
	nl();
	std::cout << "\e[35m[ TURN II ]\e[0m\n" << a.status() << '\n' << b.status() << '\n' << c.status() << "\n\n";
	a.attack(b.getName());
	b.takeDamage(a.getATK());
	nl();
	b.highFiveGuys();
	nl();
	c.highFiveGuys();
	nl();
	b.setATK(a.getHP() - 10);
	std::cout << "\e[31mAdmin intervention:\e[0m Bob high fived\n";
	std::cout << "\e[35m[ TURN III ]\e[0m\n" << a.status() << '\n' << b.status() << '\n' << c.status() << "\n\n";
	a.guardGate();
	nl();
	b.attack(a.getName());
	a.takeDamage(b.getATK());
	nl();
	c.guardGate();
	nl();
	std::cout << "\e[35m[ TURN IV ]\e[0m\n" << a.status() << '\n' << b.status() << '\n' << c.status() << "\n\n";
	a.beRepaired(a.getATK());
	nl();
	b.attack(a.getName());
	a.takeDamage(b.getATK());
	nl();
	c.attack(b.getName());
	b.takeDamage(c.getATK());
	nl();
	std::cout << "\e[35m[ TURN V ]\e[0m\n" << a.status() << '\n' << b.status() << '\n' << c.status() << "\n\n";
	a.beRepaired(a.getEnergy());
	nl();
	b.attack(c.getName());
	c.takeDamage(b.getATK());
	nl();
	c.attack(b.getName());
	b.takeDamage(c.getATK());

	nl();
	a.setEnergy(0);
	b.setEnergy(10);
	c.setEnergy(0);
	std::cout << "\e[31mAdmin intervention:\e[0m Energy drained\n";
	std::cout << "\e[35m[ TURN VI ]\e[0m\n" << a.status() << '\n' << b.status() << '\n' << c.status() << "\n\n";
	a.attack(Bob);
	b.attack(Zac);
	c.attack(Jim);

	nl();
	return (0);
}
