#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

# define GRADE_UPPER_BOUND 1
# define GRADE_LOWER_BOUND 150

class Bureaucrat
{
	private:
		const std::string	_name;
		short				_grade;
		void				checkGrade(void) const;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, short grade);
		Bureaucrat(Bureaucrat const &original);
		Bureaucrat &operator=(Bureaucrat const &original);
		~Bureaucrat();

		class GradeTooHighException: public std::exception
		{public:	const char *what() const throw();};
		class GradeTooLowException: public std::exception
		{public:	const char *what() const throw();};

		void		signForm(AForm &form) const;
		void		executeForm(AForm const &form) const;

		void		incrementGrade(void);
		void		decrementGrade(void);

		std::string	getName(void) const;
		short		getGrade(void) const;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
