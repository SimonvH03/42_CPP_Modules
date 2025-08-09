#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename T>
class	Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &original);
		Array &operator=(Array const &original);
		~Array();

		T &operator[](unsigned int n);
		T const &operator[](unsigned int n) const;

		unsigned int	size() const;

	private:
		unsigned int	_size;
		T				*_data;
};

# include "Array.tpp"

#endif
