#include "Zombie.hpp"
#include <iostream>

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
	std::cout << "Now let's make a Zombie Horde\n";

	int	N = 10;
	std::string	name = "Bob";
	std::cout << "\nWe call NewZombieHorde() to make " << N << " Zombies named " << name
		<< "\nThen let each Zombie in the Horde announce itself\n\n";

	Zombie	*ProbablyBob = ZombieHorde(N, name);
	for (int i = 0; i < N; i++)
	{
		ProbablyBob[i].announce();
	}
	delete[] ProbablyBob;
	return (0);
}