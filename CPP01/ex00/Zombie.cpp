#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Zombie constructed: " << _name << '\n';
}

Zombie::~Zombie()
{
	std::cout << "Zombie  destructed: " << _name << '\n';
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}