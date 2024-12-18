#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap
{
	private:
		FragTrap();

	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const &original);
		FragTrap &operator=(FragTrap const &original);
		~FragTrap();

		void	highFiveGuys();
};

#endif
