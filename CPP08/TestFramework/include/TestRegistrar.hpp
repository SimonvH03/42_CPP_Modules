#ifndef TESTREGISTRAR_HPP
# define TESTREGISTRAR_HPP
# include <iostream>
# include <string>
# include <memory>

# include "TestCase.hpp"
# include "TestRunner.hpp"

template<typename T>
class TestRegistrar
{
	public:
		TestRegistrar() = delete;
		explicit TestRegistrar(const std::string& testName);
		~TestRegistrar();
};

# include "TestRegistrar.tpp"

#endif
