#include <iostream>

#include "whatever.hpp"

template <typename T>
void	unitTestSwap(T &a, T &b)
{
	const T	originalA = a;
	const T	originalB = b;

	::swap(a, b);
	std::cout << "swap(" << originalA << ", " << originalB
		<< ") -> (" << a << ", " << b << ")\n"
		<< ((a == originalB && b == originalA) ? "\e[32mpass" : "\e[31mfail") << "\n\e[0m";
}

template <typename T>
void	unitTestMin(T &a, T &b)
{
	std::cout << "min (" << a << ", " << b << ") = " << ::min(a, b) << "\n"
		<< ((::min(a, b) == std::min(a, b)) ? "\e[32mpass" : "\e[31mfail") << "\n\e[0m";
}

template <typename T>
void	unitTestMax(T &a, T &b)
{
	std::cout << "max (" << a << ", " << b << ") = " << ::max(a, b) << "\n"
		<< ((::max(a, b) == std::max(a, b)) ? "\e[32mpass" : "\e[31mfail") << "\n\e[0m";
}

int	main(void)
{
	int	intA = 0;
	int	intB = 42;

	char charA = '+';
	char charB = '-';

	std::string stringA = "Hello";
	std::string stringB = "World!";

	unitTestSwap(intA, intB);
	unitTestSwap(charA, charB);
	unitTestSwap(stringA, stringB);

	unitTestMin(intA, intB);
	unitTestMin(charA, charB);
	unitTestMin(stringA, stringB);

	unitTestMax(intA, intB);
	unitTestMax(charA, charB);
	unitTestMax(stringA, stringB);
	return (0);
}
