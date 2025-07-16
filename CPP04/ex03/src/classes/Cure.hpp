#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	ICharacter;

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &original);
		Cure &operator=(Cure const &original);
		~Cure();

		AMateria	*clone() const;
		void		use(ICharacter& target);
};

#endif
