#include "Zombie.hpp"

Zombie::Zombie()
	:	_name("")
{
#ifdef	VERBOSE
	std::cout << "Zombie Default Constructor\n";
#endif
}

Zombie::~Zombie()
{
#ifdef	VERBOSE
	std::cout << "Zombie Destructor\n";
#endif
}

void	Zombie::setName(std::string name)
{
#ifdef	VERBOSE
	std::cout << "Zombie setName()\n";
#endif

	_name = name;
}

void	Zombie::announce(void)
{
#ifdef	VERBOSE
	std::cout << "Zombie announce()\n";
#endif

	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
