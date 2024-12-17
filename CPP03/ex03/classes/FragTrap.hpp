#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const &original);
		FragTrap &operator=(FragTrap const &original);
		~FragTrap();

		void	highFiveGuys();
};

#endif
