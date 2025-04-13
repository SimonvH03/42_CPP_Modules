# include <iostream>
#include "cls/AForm.hpp"
#include "cls/Bureaucrat.hpp"
#include "cls/Intern.hpp"
#include "cls/ShrubberyCreationForm.hpp"
#include "cls/RobotomyRequestForm.hpp"
#include "cls/PresidentialPardonForm.hpp"

void	nl(void)
{
	std::cout << "\n";
}

int	main(void)
{
	Bureaucrat	Alice("Alice", 1);
	Bureaucrat	Bob("Bob", 150);
	Intern		intern;

	try
	{
		AForm	*form1 = intern.makeForm(SHRUBBERY_NAME, "home");
		AForm	*form2 = intern.makeForm(ROBOTOMY_NAME, "Zach");
		AForm	*form3 = intern.makeForm(PARDON_NAME, "Yuri");

		nl();
		Alice.executeForm(*form1);
		Alice.signForm(*form1);
		Alice.executeForm(*form1);
		nl();
		Bob.executeForm(*form1);
		Bob.signForm(*form1);

		nl();
		Alice.executeForm(*form2);
		Alice.signForm(*form2);
		Alice.executeForm(*form2);
		nl();
		Bob.executeForm(*form2);
		Bob.signForm(*form2);

		nl();
		Alice.executeForm(*form3);
		Alice.signForm(*form3);
		Alice.executeForm(*form3);
		nl();
		Bob.executeForm(*form3);
		Bob.signForm(*form3);
		nl();

		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	return (0);
}
