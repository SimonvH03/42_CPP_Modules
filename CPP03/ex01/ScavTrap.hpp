#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap();

		bool guardState;

	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &original);
		ScavTrap &operator=(ScavTrap const &original);
		~ScavTrap();

		void	guardGate();

		void	takeDamage(unsigned int amount);
		std::string	status();
};

#endif
