#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
typename T::const_iterator easyfind(T &haystack, int needle)
{
	return (std::find(haystack.begin(), haystack.end(), needle));
}

#endif
