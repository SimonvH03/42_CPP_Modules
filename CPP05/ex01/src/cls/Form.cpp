#include "Form.hpp"

Form::Form() :
	_name("default Form"),
	_gradeToSign(GRADE_LOWER_BOUND),
	_gradeToExecute(GRADE_LOWER_BOUND),
	_signed(false)
{
	std::cout << "Form Default Constructor: " << *this << "\n";
}

Form::Form(std::string name, short gradeToSign, short gradeToExecute) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	std::cout << "Form Constructor: " << *this << "\n";
	checkGrades();
}

Form::Form(Form const &original) :
	_name(original.getName()),
	_gradeToSign(original.getGradeToSign()),
	_gradeToExecute(original.getGradeToExecute()),
	_signed(original.getSigned())
{
	std::cout << "Form Copy Constructor: " << *this << " from " << original << "\n";
	checkGrades();
}

Form &Form::operator=(Form const &original)
{
	std::cout << "Form Assignment Operator: " << *this << " = " << original << "\n";
	if (this != &original)
	{
		_signed = original.getSigned();
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

void	Form::checkGrades(void) const
{
	if (_gradeToSign < GRADE_UPPER_BOUND
		|| _gradeToExecute < GRADE_UPPER_BOUND)
		throw GradeTooHighException();
	else if (_gradeToSign > GRADE_LOWER_BOUND
		|| _gradeToExecute > GRADE_LOWER_BOUND)
		throw GradeTooLowException();
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	std::cout << "Form to be signed: " << *this << "\n";
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else
	{
		_signed = true;
	}
}

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

short	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

short	Form::getGradeToExecute(void) const
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
