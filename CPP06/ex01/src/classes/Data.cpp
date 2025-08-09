#include "Data.hpp"

bool	Data::operator==(Data const &other)
{
	return (c == other.c && n == other.n && str == other.str);
}
