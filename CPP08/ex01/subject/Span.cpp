#include "Span.hpp"

Span::Span()
{
#ifdef VERBOSE
	std::cout << "Span Default Constructor\n";
#endif
}

Span::Span(unsigned int N)
	:	_maxSize(N)
{
#ifdef VERBOSE
	std::cout << "Span Size Constructor\n";
#endif

	_numbers.reserve(_maxSize);
}

Span::Span(Span const &original)
	:	_maxSize(original._maxSize)
	,	_numbers(original._numbers)
{
#ifdef VERBOSE
	std::cout << "Span Copy Constructor\n";
#endif
}

Span::~Span()
{
#ifdef VERBOSE
	std::cout << "Span Destructor\n";
#endif
}

Span	&Span::operator=(Span const &original)
{
#ifdef VERBOSE
	std::cout << "Span Assignment Operator\n";
#endif

	if (this != &original)
	{
		_numbers.clear();
		addRange(original._numbers);
	}
	return (*this);
}

bool	Span::operator==(Span const &other)
const
{
#ifdef VERBOSE
	std::cout << "Span Equality Comparison Operator\n";
#endif

	return (this == &other
		|| (_maxSize == other._maxSize
		&&	_numbers == other._numbers));
}

void	Span::addNumber(int number)
{
#ifdef VERBOSE
	std::cout << "Span addNumber()\n";
#endif

	if (_numbers.size() + 1 > _maxSize)
		throw StorageFullException();

	_numbers.emplace_back(std::move(number));
}

long	Span::shortestSpan()
const
{
#ifdef VERBOSE
	std::cout << "Span shortestSpan()\n";
#endif

	if (_numbers.size() < 2)
		throw SpanningTakesTwo();

	long (*minimumDifference)(std::vector<int> const &) =
		[](std::vector<int> const &sorted) -> long
		{
			long	minDistance = std::numeric_limits<int>::max();
			for (std::vector<int>::const_iterator iterator = sorted.cbegin();
				(iterator + 1) != sorted.cend();
				++iterator)
			{
				minDistance = std::min(minDistance,
					static_cast<long>(*(iterator + 1)) - static_cast<long>(*iterator));
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

long	Span::longestSpan()
const
{
#ifdef VERBOSE
	std::cout << "Span longestSpan()\n";
#endif

	if (_numbers.size() < 2)
		throw SpanningTakesTwo();

	long	max;
	long	min;

	if (std::ranges::is_sorted(_numbers)) {
		max = _numbers.back();
		min = _numbers.front();
	} else {
		max = *std::ranges::max_element(_numbers);
		min = *std::ranges::min_element(_numbers);
	}
	return (max - min);
}

unsigned int	Span::getMaxSize() const {
	return (_maxSize);
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
