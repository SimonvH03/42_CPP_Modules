#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();

		void		announce();

	private:
		std::string	_name;
};

Zombie	*NewZombie(std::string name);
void	RandomChump(std::string name);

#endif