#ifndef TESTCREATION_HPP
# define TESTCREATION_HPP

# include "TestRegistrar.hpp"

# define TEST(test_name)                                                      \
class test_name##Test : public TestCase                                       \
{                                                                             \
	public:                                                                   \
		test_name##Test(std::string const &name) : TestCase(name) {}          \
		void run() const override;                                            \
};                                                                            \
                                                                              \
static TestRegistrar<test_name##Test>	test_name##_registration(#test_name); \
                                                                              \
void test_name##Test::run() const
/*
{
	test body
}
*/

#endif
