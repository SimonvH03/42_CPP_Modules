#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor\n";
}

Intern::Intern(Intern const &original)
{
	std::cout << "Intern Copy Constructor\n";
	*this = original;
}

Intern	&Intern::operator=(Intern const &original)
{
	std::cout << "Intern Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern Destructor\n";
}

const char	*Intern::FormNotFoundException::what() const throw()
{
	return ("Intern: requested Form name did not match any known Forms");
}

AForm	*Intern::makeForm(std::string formName, std::string target) const
{
	static const FormTableEntry knownForms[] = {
		{ShrubberyCreationForm::Name,
			[](std::string const &t){
				return new ShrubberyCreationForm(t);}},
		{RobotomyRequestForm::Name,	
			[](std::string const &t){
				return new RobotomyRequestForm(t);}},
		{PresidentialPardonForm::Name,
			[](std::string const &t){
				return new PresidentialPardonForm(t);}}
	};

	for (FormTableEntry const &entry : knownForms)
	{
		if (entry.name == formName)
		{
			std::cout << "Intern makes " << formName << "\n";
			return (entry.make(target));
		}
	}
	throw FormNotFoundException();
}
