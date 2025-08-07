#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &original);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &original);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const &executor) const;

		static const std::string	Name;
		static const short			GradeToSign = 25;
		static const short			GradeToExecute = 5;
};

#endif
