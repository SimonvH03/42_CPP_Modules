#include "classes/Animal.hpp"
#include "classes/Cat.hpp"
#include "classes/Dog.hpp"
#include "classes/WrongAnimal.hpp"
#include "classes/WrongCat.hpp"
#include <iostream>

int	main(void)
{
	Animal	*cat = new Cat();
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

	delete cat;
	delete dog;
	delete animal;

	std::cout << std::endl;

	WrongAnimal	*wrong_cat = new WrongCat();

	std::cout << std::endl;

	std::cout << wrong_cat->getType() << ": "; 
	wrong_cat->makeSound();

	delete wrong_cat;

	return (0);
}
