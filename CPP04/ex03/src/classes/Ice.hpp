#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class	ICharacter;

class Ice : public AMateria
{
	private:

	protected:

	public:
		Ice();
		Ice(Ice const &original);
		Ice &operator=(Ice const &original);
		~Ice();

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
