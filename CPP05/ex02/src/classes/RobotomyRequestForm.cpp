#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm(
		ROBOTOMY_NAME,
		ROBOTOMY_GRADE_TO_SIGN,
		ROBOTOMY_GRADE_TO_EXECUTE)
{
	std::cout << "RobotomyRequestForm Default Constructor: " << *this << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm(
		ROBOTOMY_NAME,
		target,
		ROBOTOMY_GRADE_TO_SIGN,
		ROBOTOMY_GRADE_TO_EXECUTE)
{
	std::cout << "RobotomyRequestForm Constructor: " << *this << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &original) :
	AForm(
		original.getName(),
		original.getTarget(),
		original.getGradeToSign(),
		original.getGradeToExecute())
{
	std::cout << "RobotomyRequestForm Copy Constructor: " << *this << " from " << original << "\n";
	*this = original;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &original)
{
	std::cout << "RobotomyRequestForm Assignment Operator: " << *this << " = " << original << "\n";
	if (this != &original)
	{
		AForm::operator=(original);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor: " << *this << "\n";
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::checkExec(executor);
	std::cout << "RobotomyRequestForm: buzz buzz bizz\n";
	if (std::rand() % 2)
		std::cout << "RobotomyRequestForm: "
			<< AForm::getTarget() << " has been robotomized successfully\n";
	else
		std::cout << "RobotomyRequestForm: "
			<< AForm::getTarget() << " robotomy failed\n";
}
