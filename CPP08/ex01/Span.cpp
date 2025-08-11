#include "Span.hpp"

Span::Span()
	:	N(0)
{
	std::cout << "Span Default Constructor\n";
}

Span::Span(unsigned int n)
	:	N(n)
{
	std::cout << "Span Size Constructor\n";
}

Span::Span(Span const &original)
	:	N(original.N),
		numbers(original.numbers)
{
	std::cout << "Span Copy Constructor\n";
}

Span &Span::operator=(Span const &original)
{
	std::cout << "Span Assignment Operator\n";
	if (this != &original)
	{
		N = original.N;
		numbers = original.numbers;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span Destructor\n";
}

const char	*Span::StorageFullException::what() const throw()
{
	return ("Maximum Numbers Stored");
}

void	Span::addNumber(int number)
{
	if (numbers.size() >= N)
		throw StorageFullException();
	numbers.push_back(std::move(number));
}

int	Span::shortestSpan() const
{
	std::vector<int>	copy(numbers);
	std::sort(copy.begin(), copy.end());

	unsigned int	minDistance = -1;
	for (size_t i = 0; i + 1 < copy.size(); ++i)
	{
		minDistance = std::min(minDistance, (unsigned int)std::abs(copy[i] - copy[i + 1]));
		if (minDistance == 0)
			break ;
	}
	return (minDistance);
}

int	Span::longestSpan() const
{
	std::vector<int>	copy(numbers);
	std::sort(copy.begin(), copy.end());

	size_t	size = copy.size();
	if (size < 2)
		return (-1);
	return (copy[size - 1] - copy[0]);
}
