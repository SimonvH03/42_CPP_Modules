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
	return ("Intern: formName did not match any known Form templates");
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	struct FormTemplate
	{
		const char									*name;
		std::function<AForm*(const std::string&)>	make;
	};
	static const FormTemplate formTypes[] =
	{
		{SHRUBBERY_NAME,[](const std::string &t){return new ShrubberyCreationForm(t);}},
		{ROBOTOMY_NAME,	[](const std::string &t){return new RobotomyRequestForm(t);}},
		{PARDON_NAME,	[](const std::string &t){return new PresidentialPardonForm(t);}}
	};

	for (const FormTemplate &entry : formTypes)
	{
		if (formName == entry.name)
		{
			std::cout << "Intern makes " << formName << "\n";
			return (entry.make(target));
		}
	}
	throw FormNotFoundException();
}
