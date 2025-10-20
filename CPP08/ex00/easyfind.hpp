#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
	requires std::same_as<std::iter_value_t<T>, int>
typename T::iterator easyfind(T &haystack, int needle)
{
	return (std::find(haystack.begin(), haystack.end(), needle));
}

#endif
