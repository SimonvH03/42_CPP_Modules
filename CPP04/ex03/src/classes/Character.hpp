#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Amateria;

#define INVENTORY_CAPACITY 4

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*inventory[INVENTORY_CAPACITY + 1];
		int			getInventoryUsage() const;

	protected:

	public:
		Character();
		Character(std::string _name);
		Character(Character const &original);	
		Character &operator=(Character const &original);
		~Character();

		void equip(AMateria* materia);
		void unequip(int index);
		void use(int index, ICharacter &target);
		std::string const &getName() const;
};

#endif
