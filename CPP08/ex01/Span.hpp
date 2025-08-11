#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>

class Span
{
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &original);
		Span &operator=(Span const &original);
		~Span();

		void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;

		class	StorageFullException : public std::exception
		{public:	const char *what() const throw();};
	
	private:
		unsigned int		N;
		std::vector<int>	numbers;
};

#endif
