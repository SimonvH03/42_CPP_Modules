#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include <stdlib.h>
# include <iostream>

class Cat : public Animal
{
	private:
		Brain	*brain;

	public:
		Cat();
		Cat(Cat const &original);
		Cat &operator=(Cat const &original);
		~Cat();

		void	makeSound() const;
};

#endif
