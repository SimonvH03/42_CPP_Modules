#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap
{
	protected:
		ScavTrap();
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &original);
		ScavTrap &operator=(ScavTrap const &original);
		~ScavTrap();

		bool	getGuardState() const;

		void	attack(std::string const &target);
		void	guardGate();

		void	takeDamage(unsigned int amount);

	private:
		bool	guardState;

		static const unsigned int	guardCost;
};

std::ostream	&operator<<(std::ostream &os, ScavTrap const &scavtrap);

#endif
