#include <iostream>
#include "classes/Animal.hpp"
#include "classes/Cat.hpp"
#include "classes/Dog.hpp"

int	main(void)
{
{	Animal	*cat = new Cat();
	Animal	*dog = new Dog();
	// Animal	*animal = new Animal();

	std::cout << std::endl;

	std::cout << cat->getType() << ": ";
	cat->makeSound();
	std::cout << dog->getType() << ": ";
	dog->makeSound();

	std::cout << std::endl;

	std::cout << cat->getType() << ": ";
	cat->makeSound();
	std::cout << dog->getType() << ": ";
	dog->makeSound();

	std::cout << std::endl;

	delete cat;
	delete dog;
}
{	Dog	dog;
	Dog	dog2(dog);

	std::cout << dog.getType() << ": ";
	dog.makeSound();
	std::cout << dog2.getType() << ": ";
	dog2.makeSound();

	Dog	dog3(dog);

	std::cout << dog.getType() << ": ";
	dog.makeSound();
	std::cout << dog3.getType() << ": ";
	dog3.makeSound();
}
	return (0);
}
