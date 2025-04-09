#include "Zombie.hpp"
#include <iostream>

static Zombie	*NewZombie(std::string name)
{
	Zombie *newZombie = new class Zombie(name);
	return (newZombie);
}

static void	RandomChump(std::string name)
{
	Zombie newZombie(name);
	newZombie.announce();
}

int	main(void)
{
	std::cout << "A simple demonstration of Zombies and their Class:\n";

	std::cout << "\nCase 1: Bob is dynamically allocated by NewZombie() for external use\n";
	Zombie *Bob = NewZombie("Bob");
	Bob->announce();
	delete Bob;

	std::cout << "\nCase 2: A Random Chump is constructed within RandomChump() and announces itself\n";
	RandomChump("Probably Not Bob");

	return (0);
}
