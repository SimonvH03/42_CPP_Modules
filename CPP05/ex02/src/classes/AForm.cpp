#include "AForm.hpp"

AForm::AForm() :
	_name("default AForm"),
	_target(),
	_gradeToSign(GRADE_LOWER_BOUND),
	_gradeToExecute(GRADE_LOWER_BOUND),
	_signed(false)
{
	std::cout << "AForm Default Constructor: " << *this << "\n";
}

AForm::AForm(std::string name, short gradeToSign, short gradeToExecute) :
	_name(name),
	_target("default target"),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	std::cout << "AForm Constructor: " << *this << "\n";
	checkGrades();
}

AForm::AForm(std::string name, std::string target, short gradeToSign, short gradeToExecute) :
	_name(name),
	_target(target),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	std::cout << "AForm Constructor: " << *this << "\n";
	checkGrades();
}

AForm::AForm(AForm const &original) :
	_name(original.getName()),
	_gradeToSign(original.getGradeToSign()),
	_gradeToExecute(original.getGradeToExecute()),
	_signed(original.getSigned())
{
	std::cout << "AForm Copy Constructor: " << *this << " from " << original << "\n";
	checkGrades();
}

AForm	&AForm::operator=(AForm const &original)
{
	std::cout << "AForm Assignment Operator: " << *this << " = " << original << "\n";
	if (this != &original)
	{
		_signed = original.getSigned();
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor: " << *this << "\n";
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("AForm is not signed");
}

void	AForm::checkGrades(void) const
{
	if (_gradeToSign < GRADE_UPPER_BOUND
		|| _gradeToExecute < GRADE_UPPER_BOUND)
	{
		throw GradeTooHighException();
	}
	else if (_gradeToSign > GRADE_LOWER_BOUND
		|| _gradeToExecute > GRADE_LOWER_BOUND)
	{
		throw GradeTooLowException();
	}
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	std::cout << "AForm to be signed: " << *this << "\n";
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw GradeTooLowException();
	}
	else
	{
		_signed = true;
	}
}

void	AForm::checkExec(Bureaucrat const &executor) const
{
	std::cout << "AForm to be executed: " << *this << "\n";
	if (executor.getGrade() > _gradeToExecute)
	{
		throw GradeTooLowException();
	}
	if (!_signed)
	{
		throw FormNotSignedException();
	}
}

std::string	AForm::getName(void) const
{
	return (_name);
}

std::string	AForm::getTarget(void) const
{
	return (_target);
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

short	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

short	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

std::ostream	&operator<<(std::ostream &os, AForm const &aform)
{
	os << "\"" << aform.getName() << "\" ("
		<< aform.getTarget() << ", "
		<< aform.getGradeToSign() << ", "
		<< aform.getGradeToExecute() << ", "
		<< (aform.getSigned() ? ("Signed") : ("unsigned")) << ")";
	return (os);
}
