#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>

# include "Human.hpp"
# include "Weapon.hpp"

class HumanA : Human
{
	public:
		HumanA(std::string const &name, Weapon &weapon);
		~HumanA();
		void	attack() const;

	private:
		Weapon		&_weapon;
};

#endif
