#include "AForm.hpp"

AForm::AForm()
	:	_name("default AForm"),
		_target("default target"),
		_signed(false)
{
	std::cout << "AForm Default Constructor: " << *this << "\n";
}

AForm::AForm(std::string name, Grade gradeToSign, Grade gradeToExecute)
	:	_name(name),
		_target("default target"),
		_signed(false),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute)
{
	std::cout << "AForm Constructor: " << *this << "\n";
	checkGrades();
}

AForm::AForm(std::string name, std::string target, Grade gradeToSign, Grade gradeToExecute)
	:	_name(name),
		_target(target),
		_signed(false),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute)
{
	std::cout << "AForm Constructor: " << *this << "\n";
	checkGrades();
}

AForm::AForm(AForm const &original)
	:	_name(original._name),
		_target(original._target),
		_signed(original._signed),
		_gradeToSign(original._gradeToSign),
		_gradeToExecute(original._gradeToExecute)
{
	std::cout << "AForm Copy Constructor: " << *this << " from " << original << "\n";
	checkGrades();
}

AForm	&AForm::operator=(AForm const &original)
{
	std::cout << "AForm Assignment Operator: " << *this << " = " << original << "\n";
	if (this != &original)
	{
		_signed = original._signed;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor: " << *this << "\n";
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

void	AForm::checkGrades() const
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

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	std::cout << "Form to be signed: " << *this << "\n";
	if (bureaucrat.getGrade() < _gradeToSign)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		_signed = true;
	}
}

void	AForm::checkExecutionClearance(Bureaucrat const &executor) const
{
	std::cout << "Form to be executed: " << *this << "\n";
	if (executor.getGrade() < _gradeToExecute)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	if (!_signed)
	{
		throw FormNotSignedException();
	}
}

std::string	AForm::getName() const
{
	return (_name);
}

std::string	AForm::getTarget() const
{
	return (_target);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

Grade	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

Grade	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

std::ostream	&operator<<(std::ostream &os, AForm const &aform)
{
	os << "\"" << aform.getName() << ": "
		<< aform.getTarget() << "\" ("
		<< aform.getGradeToSign() << ", "
		<< aform.getGradeToExecute() << ", "
		<< (aform.getSigned() ? "Signed" : "unsigned") << ")";
	return (os);
}
