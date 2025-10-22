#include <iostream>
#include "classes/Bureaucrat.hpp"

void	nl()
{
	std::cout << "\n";
}

int	main()
{
	Bureaucrat	alice("Alice", 43);

	Bureaucrat	bob("Bob", 150);

	Form		form("cool Form", 42, 1);

	Form		form2(form);

	Form		form3;

	try
	{
		nl();
		alice.signForm(form);
		alice.incrementGrade();
		alice.signForm(form);
		nl();

		form3 		= form;
		form3 		= form2;
		nl();

		bob.signForm(form);
		nl();

		bob.signForm(form2);
		nl();

		bob.signForm(form3);
		nl();

		bob.decrementGrade();
		nl();
	}
	catch (std::exception &e)
	{
		std::cerr << "Bureaucracy failed because: " << e.what() << "\n";
	}
	return (0);
}
