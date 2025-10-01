#ifndef ITERREF_HPP
# define ITERREF_HPP

# include <cstddef>
# include <string>
# include <typeinfo>
# include <iostream>
# include <iomanip>

# include "iter.hpp"

/*
 *	@brief compares templated iter() with explicit iterRef()
 *
 *	This function compares the behaviour between iter() and
 *	 and a corresponding iterRef() with explicitly defined types.
 *
 *	Type T must compile with std::string::operator+=(T).
 *
 *	Function must take one parameter of type T and return it by value.
 *
 *	@param begin The address to the start of an array of type T.
 *	@param length The number of elements of the array to iterate over.
 *	@param function The function applied to each element.
 *	@return whether iter() has the same behaviour as the corresponding iterRef().
*/
template <typename T, typename F>
void	iterTest(T *begin, std::size_t length, F function, const char *testName)
{
	std::string		bufferTest, bufferRef;

	iter(begin, length, [&bufferTest, function](T element){
		bufferTest += function(element);});
	iterRef(begin, length, [&bufferRef, function](T element){
		bufferRef += function(element);});

	std::cout << std::left << std::setw(12)
		<< testName << ": " << ((bufferTest == bufferRef) ? "pass" : "fail") << "\n";
}

template <typename F>
void	iterRef(int *begin, std::size_t length, F function)
{
	for (std::size_t i = 0; i < length; ++i)
	{
		function(begin[i]);
	}
}

template <typename F>
void	iterRef(int const *begin, std::size_t length, F function)
{
	for (std::size_t i = 0; i < length; ++i)
	{
		function(begin[i]);
	}
}

template <typename F>
void	iterRef(char *begin, std::size_t length, F function)
{
	for (std::size_t i = 0; i < length; ++i)
	{
		function(begin[i]);
	}
}

template <typename F>
void	iterRef(char const *begin, std::size_t length, F function)
{
	for (std::size_t i = 0; i < length; ++i)
	{
		function(begin[i]);
	}
}

template <typename F>
void	iterRef(std::string *begin, std::size_t length, F function)
{
	for (std::size_t i = 0; i < length; ++i)
	{
		function(begin[i]);
	}
}

template <typename F>
void	iterRef(std::string const *begin, std::size_t length, F function)
{
	for (std::size_t i = 0; i < length; ++i)
	{
		function(begin[i]);
	}
}

#endif