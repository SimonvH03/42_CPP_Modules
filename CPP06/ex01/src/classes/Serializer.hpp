#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <cstdint>

# include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t ptr);

	private:
		Serializer();
		Serializer(Serializer const &original);
		Serializer &operator=(Serializer const &original);
		~Serializer();
};

#endif
