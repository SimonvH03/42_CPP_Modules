#include "TestRegistrar.hpp"

TestRegistrarBase::TestRegistrarBase()
{
#ifdef VERBOSE
	std::cout << "TestRegistrarBase Default Constructor\n";
#endif
}

TestRegistrarBase::~TestRegistrarBase()
{
#ifdef VERBOSE
	std::cout << "TestRegistrarBase Destructor\n";
#endif
}
