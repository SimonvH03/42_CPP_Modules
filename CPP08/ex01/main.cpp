#include <iostream>
#include <vector>

#include "Span.hpp"

int main(void)
{
	{
		Span	span;

		try {
			span.addNumber(42);
		} catch (std::exception &except) {
			std::cerr << "Error: " << except.what() << std::endl;
		}
	}
	{
		Span	span(1);

		try {
			span.addNumber(42);
			span.addNumber(43);
		} catch (std::exception &except) {
			std::cerr << "Error: " << except.what() << std::endl;
		}
	}
	{
		Span	span0(5);

		try {
			span0.addNumber(1);
			span0.addNumber(50);
			span0.addNumber(50);
			span0.addNumber(100);
		} catch (std::exception &except) {
			std::cerr << "Error: " << except.what() << std::endl;
		}
		Span	span1(span0);
		Span	span2;
		span2 = span1;
		std::cout << "(0)shortestSpan():" << span0.shortestSpan() << "\n";
		std::cout << "(1)shortestSpan():" << span1.shortestSpan() << "\n";
		std::cout << "(2)shortestSpan():" << span2.shortestSpan() << "\n";
		std::cout << "(0)longestSpan():" << span0.longestSpan() << "\n";
		std::cout << "(1)longestSpan():" << span1.longestSpan() << "\n";
		std::cout << "(2)longestSpan():" << span2.longestSpan() << "\n";
	}
	{
		Span	span(0);

		std::cout << "shortestSpan():" << span.shortestSpan() << "\n";
		std::cout << "longestSpan():" << span.longestSpan() << "\n";
	}
	{
		const int	numbers = 1000000;
		Span		span(numbers);

		srand(time(NULL));
		try {
			for	(int i = 0; i < numbers; ++i)
			{
				span.addNumber(rand());
			}
		} catch (std::exception &except) {
			std::cerr << "Error: " << except.what() << std::endl;
		}
		std::cout << "shortestSpan():" << span.shortestSpan() << "\n";
		std::cout << "longestSpan():" << span.longestSpan() << "\n";
	}
	return (0);
}
