#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Now let's make a Zombie Horde\n";

	int	N = 10;
	std::string	name = "Bob";
	std::cout << "\nWe call NewZombieHorde() to make " << N << " Zombies named " << name
		<< "\nThen let each Zombie in the Horde announce itself\n";

	Zombie	*ProbablyBob = ZombieHorde(N, name);
	for (int i = 0; i < N; i++)
	{
		ProbablyBob[i].announce();
	}
	delete[] ProbablyBob;
	return (0);
}