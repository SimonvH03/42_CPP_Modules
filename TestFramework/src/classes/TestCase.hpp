#ifndef TESTCASE_HPP
# define TESTCASE_HPP
# include <string>
# include <iostream>
# include <stdexcept>

# define	ASSERT(expr)\
	if (!(expr))\
		throw std::runtime_error("Assertion failed: " #expr)

class TestCase
{
	protected:
		std::string name;
	public:
		TestCase(const std::string& testName) : name(testName) {}
		virtual ~TestCase() = default;
		virtual void run() = 0;
    	virtual std::string getName() const { return name; }
};

// TEST template macro
# define	TEST(test_name)                                              \
class test_name##Test : public TestCase                                  \
{                                                                        \
	public:                                                              \
		test_name##Test(const std::string& name) : TestCase(name) {}     \
		void run() override;                                             \
};                                                                       \
static TestRegistrar<test_name##Test> test_name##_registrar(#test_name); \
void test_name##Test::run()

#endif
