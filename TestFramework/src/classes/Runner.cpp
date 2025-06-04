#include "Runner.hpp"

Runner::Runner()
{
	std::cout << "Runner Default Constructor\n";
}

Runner::Runner(Runner const &original)
{
	std::cout << "Runner Copy Constructor\n";
	*this = original;
}

Runner &Runner::operator=(Runner const &original)
{
	std::cout << "Runner Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

Runner::~Runner()
{
	std::cout << "Runner Destructor\n";
}
