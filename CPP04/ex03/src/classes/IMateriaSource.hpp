#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>

class IMateriaSource
{
	private:

	protected:

	public:
		IMateriaSource();
		IMateriaSource(IMateriaSource const &original);
		IMateriaSource &operator=(IMateriaSource const &original);
		~IMateriaSource();
};

#endif
