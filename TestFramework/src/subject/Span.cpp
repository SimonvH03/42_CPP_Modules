#include "Span.hpp"

Span::Span()
{
	std::cout << "Span Default Constructor\n";
}

Span::Span(unsigned int n)
	:	_size(n)
{
	_numbers.reserve(_size);
	std::cout << "Span Size Constructor\n";
}

Span::Span(Span const &original)
	:	_size(original._size)
	,	_numbers(original._numbers)
{
	std::cout << "Span Copy Constructor\n";
}

Span::~Span()
{
	std::cout << "Span Destructor\n";
}

Span	&Span::operator=(Span const &original)
{
	std::cout << "Span Assignment Operator\n";
	if (this != &original)
	{
		_numbers.clear();
		addRange(original._numbers);
	}
	return (*this);
}

bool	Span::operator==(Span const &other) const
{
	std::cout << "Span Equality Comparison Operator\n";
	return (this == &other
		|| (_size == other._size
		&&	_numbers == other._numbers));
}

void	Span::addNumber(int number)
{
	if (_numbers.size() + 1 > _size)
		throw StorageFullException();

	_numbers.emplace_back(std::move(number));
}

int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw SpanningTakesTwo();

	int (*minimumDifference)(std::vector<int> const &) =
		[](std::vector<int> const &sorted) -> int
		{
			int	minDistance = std::numeric_limits<int>::max();
			for (std::vector<int>::const_iterator iterator = sorted.cbegin();
				(iterator + 1) != sorted.cend();
				++iterator)
			{
				minDistance = std::min(minDistance, *(iterator + 1) - *iterator);
				if (minDistance == 0)
					break ;
			}
			return (minDistance);
		};

	if (std::ranges::is_sorted(_numbers))
		return (minimumDifference(_numbers));
	else
	{
		std::vector<int>	copy(_numbers);
		std::sort(copy.begin(), copy.end());
		return (minimumDifference(copy));
	}
}

int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw SpanningTakesTwo();

	if (std::ranges::is_sorted(_numbers))
		return (_numbers.back() - _numbers.front());
	else
		return (*std::ranges::max_element(_numbers) - *std::ranges::min_element(_numbers));
}

unsigned int	Span::getSize() const {
	return (_size);
}

std::vector<int> const	&Span::getVector() const {
	return (_numbers);
}

const char	*Span::StorageFullException::what() const throw() {
	return ("Maximum Numbers Stored");
}

const char	*Span::SpanningTakesTwo::what() const throw() {
	return ("No Span Found, Not Enough Numbers");
}
