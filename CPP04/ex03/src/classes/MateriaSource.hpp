#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;

#define BOOK_CAPACITY 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*typeBook[BOOK_CAPACITY];
		int			getBookUsage() const;

	protected:

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &original);
		MateriaSource &operator=(MateriaSource const &original);
		~MateriaSource();

		void		learnMateria(AMateria *subject);
		AMateria	*createMateria(std::string const &type);
};

#endif
