#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &original);
		Dog &operator=(Dog const &original);
		~Dog();

		void	makeSound() const;
};

#endif
