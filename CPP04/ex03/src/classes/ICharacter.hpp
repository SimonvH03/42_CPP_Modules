#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <iostream>

#include "AMateria.hpp"

class	AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter();
		virtual void equip(AMateria *materia) = 0;
		virtual void unequip(int index) = 0;
		virtual void use(int index, ICharacter &target) = 0;
		virtual std::string const &getName() const = 0;
};

#endif
