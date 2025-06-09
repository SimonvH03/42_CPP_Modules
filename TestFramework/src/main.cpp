#include <iostream>
#include "classes/TestCase.hpp"
#include "classes/TestRunner.hpp"
#include "classes/TestRegistrar.hpp"

TEST(addition)
{
	ASSERT(2 + 2 == 5);
}

int	main(void)
{
	TestRunner::get().runAll();
	return (0);
}
