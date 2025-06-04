#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed		a;
	Fixed		b(5.1f);
	Fixed		c(3.15f);

	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";
	a++;
	std::cout << a << "\n";
	a++;
	std::cout << a << "\n";
	a--;
	std::cout << a << "\n";
	std::cout << ++a << "\n";
	std::cout << --a << "\n";
	a = b;
	std::cout << a << "\n";
	a++;
	std::cout << a << "\n";
	a += c;
	std::cout << a << "\n";
	a *= b;
	std::cout << a << "\n";
	a /= c;
	std::cout << a << "\n";
	a /= b;
	std::cout << a << "\n";
	a *= c;
	std::cout << a << "\n";
	std::cout << a << " >  " << c << ": " << ((a > c) ? "true" : "false") << "\n";
	std::cout << a << " >= " << c << ": " << ((a >= c) ? "true" : "false") << "\n";
	std::cout << a << " <  " << c << ": " << ((a < c) ? "true" : "false") << "\n";
	std::cout << a << " <= " << c << ": " << ((a <= c) ? "true" : "false") << "\n";
	std::cout << a << " == " << c << ": " << ((a == c) ? "true" : "false") << "\n";
	std::cout << a << " != " << c << ": " << ((a != c) ? "true" : "false") << "\n";

	return (0);
}
