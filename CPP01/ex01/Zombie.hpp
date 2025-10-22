#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class	Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	setName(std::string name);
		void	announce();

	private:
		std::string	_name;
};

#endif
