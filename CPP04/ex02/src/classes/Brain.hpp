#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <fstream>
# include <string>

#define BRAIN_CAPACITY 100

class Brain
{
	private:
		void		fileStudy(std::string fileName);
		std::string	ideas[BRAIN_CAPACITY];
		int			knowledge;
		int			thoughts_had;

	public:
		Brain();
		Brain(Brain const &original);
		Brain &operator=(Brain const &original);
		~Brain();

		void		think();
};

#endif
