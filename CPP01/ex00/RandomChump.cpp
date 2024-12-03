#include "Zombie.hpp"

void	RandomChump(std::string name)
{
	Zombie newZombie(name);
	newZombie.announce();
}