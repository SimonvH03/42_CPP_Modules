#include <iostream>
#include "classes/AForm.hpp"
#include "classes/Bureaucrat.hpp"
#include "classes/ShrubberyCreationForm.hpp"
#include "classes/RobotomyRequestForm.hpp"
#include "classes/PresidentialPardonForm.hpp"

void	nl(void)
{
	std::cout << "\n";
}

int	main(void)
{
	Bureaucrat				Alice("Alice", 1);
	Bureaucrat				Bob("Bob", 150);

	AForm					*form = new ShrubberyCreationForm("abstract");
	ShrubberyCreationForm	shrubbery("shrubbish");
	RobotomyRequestForm		robotomy("client");
	PresidentialPardonForm	pardon("peasant");

	// try
	// {
	// 	nl();
	// 	Alice.executeForm(shrubbery);
	// 	Alice.signForm(shrubbery);
	// 	Alice.executeForm(shrubbery);
	// 	nl();
	// 	Alice.executeForm(*form);
	// 	Alice.signForm(*form);
	// 	Alice.executeForm(*form);
	// 	nl();
	// 	Bob.executeForm(shrubbery);
	// 	Bob.signForm(shrubbery);
	// 	nl();
	// 	Bob.executeForm(*form);
	// 	Bob.signForm(*form);
	// 	nl();
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr << e.what() << "\n";
	// }
	try
	{
		nl();
		Alice.executeForm(shrubbery);
		Alice.signForm(shrubbery);
		Alice.executeForm(shrubbery);
		nl();
		Bob.executeForm(shrubbery);
		Bob.signForm(shrubbery);
		nl();
		Alice.executeForm(robotomy);
		Alice.signForm(robotomy);
		Alice.executeForm(robotomy);
		nl();
		Bob.executeForm(robotomy);
		Bob.signForm(robotomy);
		nl();
		Alice.executeForm(pardon);
		Alice.signForm(pardon);
		Alice.executeForm(pardon);
		nl();
		Bob.executeForm(pardon);
		Bob.signForm(pardon);
		nl();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	delete form;
	return (0);
}
