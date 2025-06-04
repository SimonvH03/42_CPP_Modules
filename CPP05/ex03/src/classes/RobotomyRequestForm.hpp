#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <cstdlib>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

# define ROBOTOMY_NAME				"RobotomyRequestForm"
# define ROBOTOMY_GRADE_TO_SIGN		72
# define ROBOTOMY_GRADE_TO_EXECUTE	45

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &original);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &original);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const &executor) const;
};

#endif
