#include "Form.hpp"

Form::Form()
	:	_name("default Form"),
		_signed(false),
		_gradeToSign(Bureaucrat::LowerBound),
		_gradeToExecute(Bureaucrat::LowerBound)
{
	std::cout << "Form Default Constructor: " << *this << "\n";
}

Form::Form(std::string name, short gradeToSign, short gradeToExecute)
	:	_name(name),
		_signed(false),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute)
{
	std::cout << "Form Constructor: " << *this << "\n";
	checkGrades();
}

Form::Form(Form const &original)
	:	_name(original._name),
		_signed(original._signed),
		_gradeToSign(original._gradeToSign),
		_gradeToExecute(original._gradeToExecute)
{
	std::cout << "Form Copy Constructor: " << *this << " from " << original << "\n";
	checkGrades();
}

Form &Form::operator=(Form const &original)
{
	std::cout << "Form Assignment Operator: " << *this << " = " << original << "\n";
	if (this != &original)
	{
		_signed = original._signed;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form Destructor: " << *this << "\n";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

void	Form::checkGrades() const
{
	if (_gradeToSign < Bureaucrat::UpperBound
		|| _gradeToExecute < Bureaucrat::UpperBound)
	{
		throw GradeTooHighException();
	}
	if (_gradeToSign > Bureaucrat::LowerBound
		|| _gradeToExecute > Bureaucrat::LowerBound)
	{
		throw GradeTooLowException();
	}
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	std::cout << "Form to be signed: " << *this << "\n";
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw GradeTooLowException();
	}
	_signed = true;
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

short	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

short	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "\"" << form.getName() << "\" ("
		<< (form.getSigned() ? ("Signed") : ("unsigned")) << ", "
		<< form.getGradeToSign() << ", "
		<< form.getGradeToExecute() << ")";
	return (os);
}
