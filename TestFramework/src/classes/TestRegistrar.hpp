#ifndef TESTREGISTRAR_HPP
# define TESTREGISTRAR_HPP
# include <string>
# include <memory>

class TestRegistrarBase
{
	public:
		virtual ~TestRegistrarBase() = default;
};

template<typename T>
class TestRegistrar : public TestRegistrarBase
{
	public:
		TestRegistrar(const std::string& testName) {
			TestRunner::get().add(std::make_unique<T>(testName));
		}
};

#endif
