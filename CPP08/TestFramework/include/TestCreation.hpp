#ifndef TESTCREATION_HPP
# define TESTCREATION_HPP

# include "TestRegistrar.hpp"

# define TEST(test_name)                                                        \
class test_name##_Test : public TestCase                                        \
{                                                                               \
	public:                                                                     \
		explicit test_name##_Test(std::string const &name);                     \
		void run() const override;                                              \
};                                                                              \
\
static TestRegistrar<test_name##_Test>	test_name##_registration(#test_name);   \
\
test_name##_Test::test_name##_Test(std::string const &name)                     \
	:	TestCase(name)                                                          \
{}                                                                              \
\
void test_name##_Test::run() const
/*
{
	test body
}
*/

#endif
