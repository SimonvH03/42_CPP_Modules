#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <exception>
# include <algorithm>
# include <ranges>
# include <vector>
# include <limits>
# include <functional>

class Span
{
public:
	Span();
	Span(unsigned int N);
	Span(Span const &original);
	~Span();

	Span	&operator=(Span const &original);
	bool	operator==(Span const &other) const;

	void	addNumber(int number);

	long	shortestSpan() const;
	long	longestSpan() const;


	template <std::ranges::range R>
		requires std::same_as<std::ranges::range_value_t<R>, int>
	Span(R range);
	template <std::ranges::range R>
		requires std::same_as<std::ranges::range_value_t<R>, int>
	Span	&operator=(R const &range);
	template <std::ranges::range R>
		requires std::equality_comparable_with<std::ranges::range_value_t<R>, int>
	bool	operator==(R const &range) const;
	template <std::ranges::range R>
		requires std::same_as<std::ranges::range_value_t<R>, int>
	void	addRange(R range);

	template <std::forward_iterator Iter>
		requires std::same_as<std::iter_value_t<Iter>, int>
	Span(Iter first, Iter last);
	template <std::forward_iterator Iter>
		requires std::same_as<std::iter_value_t<Iter>, int>
	void	addRange(Iter first, Iter last);


	unsigned int			getMaxSize() const;
	std::vector<int> const	&getVector() const;

	class	StorageFullException : public std::exception
	{public:	const char *what() const throw();};
	class	SpanningTakesTwo : public std::exception
	{public:	const char *what() const throw();};

private:
	unsigned int const	_maxSize = 0;
	std::vector<int>	_numbers;
};

# include "Span.tpp"

#endif
