#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm(
		PARDON_NAME,
		PARDON_GRADE_TO_SIGN,
		PARDON_GRADE_TO_EXECUTE)
{
	std::cout << "PresidentialPardonForm Default Constructor: " << *this << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm(
		PARDON_NAME,
		target,
		PARDON_GRADE_TO_SIGN,
		PARDON_GRADE_TO_EXECUTE)
{
	std::cout << "PresidentialPardonForm Constructor: " << *this << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &original) :
	AForm(
		original.getName(),
		original.getTarget(),
		original.getGradeToSign(),
		original.getGradeToExecute())
{
	std::cout << "PresidentialPardonForm Copy Constructor: " << *this << " from " << original << "\n";
	*this = original;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &original)
{
	std::cout << "PresidentialPardonForm Assignment Operator: " << *this << " = " << original << "\n";
	if (this != &original)
	{
		AForm::operator=(original);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor: " << *this << "\n";
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		AForm::checkExec(executor);
		std::cout << "PresidentialPardonForm: "
			<< AForm::getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
		return ;
	}
}
