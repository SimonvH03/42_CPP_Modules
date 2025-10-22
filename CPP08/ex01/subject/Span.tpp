template <std::ranges::range R>
	requires std::same_as<std::ranges::range_value_t<R>, int>
Span::Span(R range)
	:	_maxSize(std::ranges::size(range)),
		_numbers(range.begin(), range.end())
{
#ifdef VERBOSE
	std::cout << "Span Range Constructor\n";
#endif
}

template <std::forward_iterator Iter>
	requires std::same_as<std::iter_value_t<Iter>, int>
Span::Span(Iter first, Iter last)
	:	_maxSize(std::distance(first, last)),
		_numbers(first, last)
{
#ifdef VERBOSE
	std::cout << "Span Iterator Range Constructor\n";
#endif
}

template <std::ranges::range R>
	requires std::same_as<std::ranges::range_value_t<R>, int>
Span	&Span::operator=(R const &range)
{
#ifdef VERBOSE
	std::cout << "Span Range Assignment Operator\n";
#endif

	_numbers.clear();
	addRange(range);
	return (*this);
}

template <std::ranges::range R>
	requires std::equality_comparable_with<std::ranges::range_value_t<R>, int>
bool	Span::operator==(R const &range)
const
{
#ifdef VERBOSE
	std::cout << "Span Range Equality Comparison Operator\n";
#endif

	return (std::ranges::equal(_numbers, range));
}

template <std::ranges::range R>
	requires std::same_as<std::ranges::range_value_t<R>, int>
void	Span::addRange(R range)
{
#ifdef VERBOSE
	std::cout << "Span addRange Range\n";
#endif

	if (_numbers.size() + std::ranges::size(range) > _maxSize)
		throw StorageFullException();

	_numbers.insert(_numbers.end(), range.begin(), range.end());
}

template <std::forward_iterator Iter>
	requires std::same_as<std::iter_value_t<Iter>, int>
void	Span::addRange(Iter first, Iter last)
{
#ifdef VERBOSE
	std::cout << "Span addRange Iterator Range\n";
#endif

	if (_numbers.size() + std::distance(first, last) > _maxSize)
		throw StorageFullException();

	_numbers.insert(_numbers.end(), first, last);
}
