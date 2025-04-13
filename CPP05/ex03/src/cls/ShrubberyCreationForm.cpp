#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm(
		SHRUBBERY_NAME,
		SHRUBBERY_GRADE_TO_SIGN,
		SHRUBBERY_GRADE_TO_EXECUTE)
{
	std::cout << "ShrubberyCreationForm Default Constructor: " << *this << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm(
		SHRUBBERY_NAME,
		target,
		SHRUBBERY_GRADE_TO_SIGN,
		SHRUBBERY_GRADE_TO_EXECUTE)
{
	std::cout << "ShrubberyCreationForm Constructor: " << *this << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &original) :
	AForm(
		original.getName(),
		original.getTarget(),
		original.getGradeToSign(),
		original.getGradeToExecute())
{
	std::cout << "ShrubberyCreationForm Copy Constructor: " << *this << " from " << original << "\n";
	*this = original;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &original)
{
	std::cout << "ShrubberyCreationForm Assignment Operator: " << *this << " = " << original << "\n";
	if (this != &original)
	{
		AForm::operator=(original);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor: " << *this << "\n";
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		AForm::checkExec(executor);
		std::string	filename = AForm::getTarget() + "_shrubbery";
		std::ofstream ofs(filename.c_str(), std::ios::out | std::ios::trunc);
		if (!ofs.is_open())
			throw std::ios_base::failure("ShrubberyCreationForm: file open failed");
		ofs << "      _+_\n"
			<< "     _-_-_\n"
			<< "    _+_+_+_\n"
			<< "   _-_-_-_-_\n"
			<< "  _+_+_+_+_+_\n"
			<< " _-_-_-_-_-_-_\n"
			<< "      | |\n"
			<< "      | |\n"
			<< "      | |";
		ofs.close();
		std::cout << "ShrubberyCreationForm: Shrubbery was spawned in \""
			<< AForm::getTarget() << "_shrubbery\n\"";
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
		return ;
	}
}
