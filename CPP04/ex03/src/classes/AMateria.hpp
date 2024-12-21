#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class AMateria
{
	private:

	protected:

	public:
		AMateria();
		AMateria(AMateria const &original);
		AMateria &operator=(AMateria const &original);
		~AMateria();
};

#endif
