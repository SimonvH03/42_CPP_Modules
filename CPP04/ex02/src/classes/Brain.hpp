#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

extern "C" {
	#include "get_next_line/get_next_line.h"
}

#define BRAIN_CAPACITY 10

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
