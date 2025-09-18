#include <iostream>
#include "classes/Base.hpp"
#include "classes/A.hpp"
#include "classes/B.hpp"
#include "classes/C.hpp"
#include <random>

static	int	randomFromRange(int min, int max)
{
	static std::random_device		rd;
	static std::mt19937				gen(rd());
	std::uniform_int_distribution<> dist(min, max);

	return dist(gen);
}

Base	*generate()
{
	Base	*ptr;

	switch (randomFromRange(0, 2))
	{
		case 0:
			ptr = new A;
			break ;
		case 1:
			ptr = new B;
			break ;
		case 2:
			ptr = new C;
	}
	return (ptr);
}

void	identify(Base *ptr)
{
	if (dynamic_cast<A *>(ptr) != nullptr)
		std::cout << "A";
	if (dynamic_cast<B *>(ptr) != nullptr)
		std::cout << "B";
	if (dynamic_cast<C *>(ptr) != nullptr)
		std::cout << "C";
}

void	identify(Base &ptr)
{
	try {
		(void)dynamic_cast<A&>(ptr);
		std::cout << "A";
	} catch (std::bad_cast &except) {}
	try {
		(void)dynamic_cast<B&>(ptr);
		std::cout << "B";
	} catch (std::bad_cast &except) {}
	try {
		(void)dynamic_cast<C&>(ptr);
		std::cout << "C";
	} catch (std::bad_cast &except) {}
}

int	main(void)
{
	Base	*ptr = generate();

	identify(ptr);
	std::cout << " Pointer Type ID\n";
	identify(*ptr);
	std::cout << " Reference Type ID\n";
	delete ptr;
	return (0);
}
