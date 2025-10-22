#include <iostream>
#include "classes/Serializer.hpp"
#include "classes/Data.hpp"

int	main(void)
{
	{
		Data	data;
		Data	*dataPtr = Serializer::deserialize(Serializer::serialize(&data));

		std::cout << "Stack variable: "
			<< ((*dataPtr == data) ? "pass" : "fail") << "\n"
			<< dataPtr << "\n" << &data << "\n";
	}
	{
		Data *dataPtr0 = new Data();
		Data *dataPtr1 = Serializer::deserialize(Serializer::serialize(dataPtr0));

		std::cout << "Heap allocation: "
			<< ((*dataPtr1 == *dataPtr0) ? "pass" : "fail")  << "\n"
			<< dataPtr1 << "\n" << dataPtr0 << "\n";
	}
}
