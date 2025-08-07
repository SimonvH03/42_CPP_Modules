#include "ShrubberyCreationForm.hpp"

const std::string	ShrubberyCreationForm::Name = "ShrubberyCreationForm";

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm(
			Name,
			GradeToSign,
			GradeToExecute)
{
	std::cout << "ShrubberyCreationForm Default Constructor: " << *this << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:	AForm(
			Name,
			target,
			GradeToSign,
			GradeToExecute)
{
	std::cout << "ShrubberyCreationForm Constructor: " << *this << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &original)
	:	AForm(
			original.getName(),
			original.getTarget(),
			original.getGradeToSign(),
			original.getGradeToExecute())
{
	std::cout << "ShrubberyCreationForm Copy Constructor: " << *this << " from " << original << "\n";
	*this = original;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &original)
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
	AForm::checkExec(executor);
	std::string	filename = AForm::getTarget() + "_shrubbery";
	std::ofstream ofs(filename.c_str(), std::ios::out | std::ios::trunc);
	if (!ofs.is_open())
		throw std::ios_base::failure("ShrubberyCreationForm: file open failed");
	ofs << "      '.,\n"
		<< "        'b      *\n"
		<< "         '$    #.\n"
		<< "          $:   #:\n"
		<< "          *#  @):\n"
		<< "          :@,@):\n"
		<< "          ,.**:'\n"
		<< ",         :@@*: ..**'\n"
		<< " '#o.    .:(@'.@*''\n"
		<< "    'bq,..:,@@*'   ,*\n"
		<< "    ,p$q8,:@)'  .p*'\n"
		<< "   '    '@@Pp@@*'\n"
		<< "         Y7'.'\n"
		<< "        :@):.\n"
		<< "       .:@:'.\n"
		<< "     .::(@:.\n"
		<< "~ courtesy of Sam Blumenstein";
	ofs.close();
	std::cout << "ShrubberyCreationForm: Shrubbery was spawned in \""
		<< AForm::getTarget() << "_shrubbery\n\"";
}
