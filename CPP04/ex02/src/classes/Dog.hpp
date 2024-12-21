#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include <stdlib.h>
# include <iostream>

class Dog : public Animal
{
	private:
		Brain	*brain;
		int		levelOfThought;
		void	think();

	public:
		Dog();
		Dog(Dog const &original);
		Dog &operator=(Dog const &original);
		~Dog();

		void	makeSound();
};

#endif
