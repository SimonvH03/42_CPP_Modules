#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

#include "ICharacter.hpp"

class	ICharacter;

class AMateria
{
	private:

	protected:
		std::string	type;

	public:
		AMateria();
		AMateria(std::string const &_type);
		AMateria(AMateria const &original);
		AMateria &operator=(AMateria const &original);
		virtual ~AMateria();

		virtual void		use(ICharacter &target);
		virtual AMateria	*clone() const = 0;
		std::string const	&getType() const const;
};

#endif
