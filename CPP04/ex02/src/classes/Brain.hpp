#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <fstream>
# include <string>

#define BRAIN_CAPACITY 100

class Brain
{
	private:
		int	intelligence;

	public:
		Brain();
		Brain(Brain const &original);
		Brain &operator=(Brain const &original);
		~Brain();

		std::string	ideas[BRAIN_CAPACITY];
		void		fileStudy(std::string fileName);
};

#endif
