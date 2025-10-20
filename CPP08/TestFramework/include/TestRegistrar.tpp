#include "TestRegistrar.hpp"

template<typename T>
TestRegistrar<T>::TestRegistrar(const std::string& testName)
{
#ifdef VERBOSE
	std::cout << "TestRegistrar Name Constructor: " << testName << "\n";
#endif

	TestRunner::get().addTest(std::make_unique<T>(testName));
}

template<typename T>
TestRegistrar<T>::~TestRegistrar()
{
#ifdef VERBOSE
	std::cout << "TestRegistrar Destructor\n";
#endif
}
