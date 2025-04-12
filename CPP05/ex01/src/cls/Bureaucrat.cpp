#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	_name("Bureaucrat"),
	_grade(150)
{
	std::cout << "Bureaucrat Default Constructor: " << *this << "\n";
	checkGrade();
}

Bureaucrat::Bureaucrat(std::string name, short grade) :
	_name(name),
	_grade(grade)
{
	std::cout << "Bureaucrat Constructor: " << *this << "\n";
	checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const &original) :
	_name(original.getName()),
	_grade(original.getGrade())
{
	std::cout << "Bureaucrat Copy Constructor: " << *this << " from " << original << "\n";
	checkGrade();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &original)
{
	std::cout << "Bureaucrat Assignment Operator: " << *this << " = " << original << "\n";
	if (this != &original)
	{
		_grade = original.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor: " << *this << "\n";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too high");
}

void	Bureaucrat::checkGrade(void) const
{
	if (_grade < GRADE_UPPER_BOUND)
		throw GradeTooHighException();
	else if (_grade > GRADE_LOWER_BOUND)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn't sign " << form
			<< " because: " << e.what() << "\n";
	}
}

void	Bureaucrat::incrementGrade(void)
{
	_grade--;
	std::cout << "Bureaucrat grade incremented: " << *this << "\n";
	checkGrade();
}

void	Bureaucrat::decrementGrade(void)
{
	_grade++;
	std::cout << "Bureaucrat grade decremented: " << *this << "\n";
	checkGrade();
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

short	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << "\"" << bureaucrat.getName() << "\" (grade " << bureaucrat.getGrade() << ")";
	return (os);
}
