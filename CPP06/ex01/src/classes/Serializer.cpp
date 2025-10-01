#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor\n";
}

Serializer::Serializer(Serializer const &original)
{
	std::cout << "Serializer Copy Constructor\n";
	*this = original;
}

Serializer &Serializer::operator=(Serializer const &original)
{
	std::cout << "Serializer Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer Destructor\n";
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t ptr)
{
	return (reinterpret_cast<Data*>(ptr));
}
