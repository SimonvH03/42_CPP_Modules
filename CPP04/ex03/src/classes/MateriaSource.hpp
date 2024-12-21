#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>

class MateriaSource
{
	private:

	protected:

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &original);
		MateriaSource &operator=(MateriaSource const &original);
		~MateriaSource();
};

#endif
