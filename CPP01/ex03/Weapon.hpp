#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	public:
		Weapon(std::string const &type);
		~Weapon();

		void				setType(std::string const &type);
		std::string	const	&getType() const;

	private:
		std::string	_type;
};

#endif
