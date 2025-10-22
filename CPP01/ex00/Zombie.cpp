#include "Zombie.hpp"

Zombie::Zombie(std::string name)
	:	_name(name)
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

void	Zombie::announce(void)
const
{
#ifdef	VERBOSE
	std::cout << "Zombie announce()\n";
#endif

	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
