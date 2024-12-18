#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap
{
	private:
		bool 			guardState;
		unsigned int	guardCost;

	protected:
		ScavTrap();

	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &original);
		ScavTrap &operator=(ScavTrap const &original);
		~ScavTrap();

		void	guardGate();

		void	takeDamage(unsigned int amount);
		std::string	status() const;
};

#endif
