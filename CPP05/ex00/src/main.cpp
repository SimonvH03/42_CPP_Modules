# include <iostream>
#include "classes/Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	alice(1);
	std::cout << alice << '\n';

	Bureaucrat	bob(150);
	std::cout << bob << '\n';

	Bureaucrat	carl(alice);
	std::cout << carl << '\n';

	Bureaucrat	dan;
	dan = bob;
	std::cout << dan << '\n';

	try
	{
		alice.decrementGrade();
		bob.incrementGrade();
		carl.decrementGrade();
		dan.incrementGrade();
		std::cout << alice << '\n';
		std::cout << bob << '\n';
		std::cout << carl << '\n';
		std::cout << dan << '\n';
		// alice.incrementGrade();
		// bob.decrementGrade();
		// carl.incrementGrade();
		// dan.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
