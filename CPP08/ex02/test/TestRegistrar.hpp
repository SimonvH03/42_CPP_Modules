#ifndef TESTREGISTRAR_HPP
# define TESTREGISTRAR_HPP
# include <iostream>
# include <string>
# include <memory>

# include "TestCase.hpp"
# include "TestRunner.hpp"

class TestRegistrarBase
{
	public:
		TestRegistrarBase();
		virtual	~TestRegistrarBase();
};

template<typename T>
class TestRegistrar : public TestRegistrarBase
{
	public:
		explicit TestRegistrar(const std::string& testName);
		~TestRegistrar();
	private:
};

# include "TestRegistrar.tpp"

#endif
