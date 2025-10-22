#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>

# include "Human.hpp"
# include "Weapon.hpp"

class HumanB : Human
{
	public:
		HumanB(std::string const &name);
		~HumanB();

		void	setWeapon(Weapon *weapon);
		void	attack() const;

	private:
		Weapon		*_weapon;
};

#endif
