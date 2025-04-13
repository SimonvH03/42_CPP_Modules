#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

# define PARDON_NAME				"PresidentialPardonForm"
# define PARDON_GRADE_TO_SIGN		25
# define PARDON_GRADE_TO_EXECUTE	5

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &original);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &original);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const &executor) const;
};

#endif
