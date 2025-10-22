#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA	alice("Alice", club);

		alice.attack();
		club.setType("other type of club");
		alice.attack();
	}
	std::cout << "\n";
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB	bob("Bob");

		bob.attack();
		bob.setWeapon(&club);
		bob.attack();
		club.setType("other type of club");
		bob.attack();
	}
	return (0);
}
