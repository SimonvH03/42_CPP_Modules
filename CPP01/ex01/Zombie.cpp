#include "Zombie.hpp"

Zombie::Zombie()
{
	_name = "";
	std::cout << "Zombie constructed" << '\n';
}

Zombie::~Zombie()
{
	std::cout << "Zombie  destructed: " << _name << '\n';
}

void	Zombie::setName(std::string name)
{
	_name = name;
	std::cout << "Zombie named: " << _name << '\n';
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}