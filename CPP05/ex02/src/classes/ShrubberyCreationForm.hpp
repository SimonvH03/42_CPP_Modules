#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &original);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &original);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const &executor) const;

		static const std::string	Name;
		static const short			GradeToSign = 145;
		static const short			GradeToExecute = 137;
};

#endif
