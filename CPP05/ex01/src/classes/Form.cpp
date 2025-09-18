#include "Form.hpp"

Form::Form()
	:	_name("empty Form"),
		_signed(false)
{
	std::cout << "Form Default Constructor: " << *this << "\n";
}

Form::Form(std::string name, Grade gradeToSign, Grade gradeToExecute)
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

Form	&Form::operator=(Form const &original)
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

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

void	Form::checkGrades() const
{
	if (_gradeToExecute > Grade::UpperBound
		|| _gradeToSign > Grade::UpperBound)
	{
		throw GradeTooHighException();
	}
	if (_gradeToExecute < Grade::LowerBound
		|| _gradeToSign < Grade::LowerBound)
	{
		throw GradeTooLowException();
	}
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	std::cout << "Form to be signed: " << *this << "\n";
	if (bureaucrat.getGrade() < _gradeToSign)
	{
		throw Bureaucrat::GradeTooLowException();
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

Grade	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

Grade	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

std::ostream	&operator<<(std::ostream &os, Form const &form)
{
	os << "\"" << form.getName() << "\" ("
		<< form.getGradeToSign() << ", "
		<< form.getGradeToExecute() << ", "
		<< (form.getSigned() ? ("Signed") : ("unsigned")) << ")";
	return (os);
}
