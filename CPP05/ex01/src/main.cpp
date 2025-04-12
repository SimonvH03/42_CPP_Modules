# include <iostream>
#include "cls/Bureaucrat.hpp"

void	nl(void)
{
	std::cout << '\n';
}

int	main(void)
{
	Bureaucrat	alice("Alice", 43);

	Bureaucrat	bob("Bob", 150);

	Form		form("cool Form", 42, 1);

	Form		form2;
	form2 		= form;

	Form		form3(form);

	try
	{
		nl();
		alice.signForm(form);
		alice.incrementGrade();
		alice.signForm(form);
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
		std::cerr << "Bureaucracy failed because: " << e.what() << '\n';
	}
	return (0);
}
