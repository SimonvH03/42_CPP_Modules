#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		DiamondTrap();

		std::string	Name;

	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &original);
		DiamondTrap &operator=(DiamondTrap const &original);
		~DiamondTrap();

		void	whoAmI();
};

#endif
