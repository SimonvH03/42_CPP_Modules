#include <iostream>
#include "classes/Animal.hpp"
#include "classes/Cat.hpp"
#include "classes/Dog.hpp"
#include "classes/WrongAnimal.hpp"
#include "classes/WrongCat.hpp"

int	main(void)
{
{	Animal	*cat = new Cat();
	Animal	*dog = new Dog();
	Animal	*animal = new Animal();

	std::cout << std::endl;

	std::cout << cat->getType() << ": ";
	cat->makeSound();
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << animal->getType() << ": ";
	animal->makeSound();

	std::cout << std::endl;

	std::cout << cat->getType() << ": ";
	cat->makeSound();
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << animal->getType() << ": ";
	animal->makeSound();

	std::cout << std::endl;

	delete cat;
	delete dog;
	delete animal;
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
{	Cat	cat;

	for (int i = 0; i < BRAIN_CAPACITY + 10; i++)
	{
		std::cout << cat.getType() << ": ";
		cat.makeSound();
	}
}
{	std::cout << std::endl;

	WrongAnimal	*wrong_cat = new WrongCat();

	std::cout << std::endl;

	std::cout << wrong_cat->getType() << ": ";
	wrong_cat->makeSound();

	delete wrong_cat;
}
	return (0);
}
