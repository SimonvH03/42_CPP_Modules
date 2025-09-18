#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:	_name("Bureaucrat")
{
	std::cout << "Bureaucrat Default Constructor: " << *this << "\n";
}

Bureaucrat::Bureaucrat(std::string name, Grade grade)
	:	_name(name),
		_grade(grade)
{
	std::cout << "Bureaucrat Constructor: " << *this << "\n";
	checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const &original)
	:	_name(original._name),
		_grade(original._grade)
{
	std::cout << "Bureaucrat Copy Constructor: " << *this << " from " << original << "\n";
	checkGrade();
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &original)
{
	std::cout << "Bureaucrat Assignment Operator: " << *this << " = " << original << "\n";
	if (this != &original)
	{
		_grade = original._grade;
		checkGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor: " << *this << "\n";
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low");
}

void	Bureaucrat::checkGrade() const
{
	if (_grade > Grade::UpperBound)
		throw GradeTooHighException();
	if (_grade < Grade::LowerBound)
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

void	Bureaucrat::incrementGrade()
{
	++_grade;
	std::cout << "Bureaucrat grade incremented: " << *this << "\n";
	checkGrade();
}

void	Bureaucrat::decrementGrade()
{
	--_grade;
	std::cout << "Bureaucrat grade decremented: " << *this << "\n";
	checkGrade();
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

Grade	Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
