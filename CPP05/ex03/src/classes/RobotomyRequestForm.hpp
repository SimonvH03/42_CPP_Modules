#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <cstdlib>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &original);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &original);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const &executor) const;

		static const std::string	Name;
		static const Grade			GradeToSign;
		static const Grade			GradeToExecute;
};

#endif
