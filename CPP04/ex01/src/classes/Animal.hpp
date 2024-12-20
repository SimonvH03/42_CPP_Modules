#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(Animal const &original);
		Animal &operator=(Animal const &original);
		virtual ~Animal();

		std::string		getType();
		virtual void	makeSound();
};

#endif
