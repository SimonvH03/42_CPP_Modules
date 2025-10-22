#include <iostream>

#include "Zombie.hpp"

static Zombie	*ZombieHorde(int N, std::string name)
{
	Zombie	*zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].setName(name);
	}
	return (zombieHorde);
}

int	main(void)
{
	int			N = 10;
	std::string	name = "Bob";

	std::cout
		<< "Now let's make a Zombie Horde\n"
		<< "\nWe call NewZombieHorde() to make " << N << " Zombies named " << name
		<< "\nThen let each Zombie in the Horde announce itself\n\n";

	Zombie	*Bobs = ZombieHorde(N, name);
	for (int i = 0; i < N; i++)
	{
		Bobs[i].announce();
	}
	delete[] Bobs;
	return (0);
}
