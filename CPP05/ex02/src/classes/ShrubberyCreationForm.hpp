#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

# define SHRUBBERY_NAME				"ShrubberyCreationForm"
# define SHRUBBERY_GRADE_TO_SIGN	145
# define SHRUBBERY_GRADE_TO_EXECUTE	137

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &original);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &original);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const &executor) const;
};

#endif
