#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, Grade gradeToSign, Grade gradeToExecute);
		AForm(std::string name, std::string target, Grade gradeToSign, Grade gradeToExecute);
		AForm(AForm const &original);
		AForm &operator=(AForm const &original);
		virtual ~AForm();

		class GradeTooHighException: public std::exception
		{public:	const char *what() const throw();};
		class GradeTooLowException: public std::exception
		{public:	const char *what() const throw();};

		class FormNotSignedException: public std::exception
		{public:	const char *what() const throw();};

virtual void		execute(Bureaucrat const &executor) const = 0;

		void		beSigned(Bureaucrat const &bureaucrat);

		std::string	getName() const;
		std::string	getTarget() const;
		bool		getSigned() const;
		Grade		getGradeToSign() const;
		Grade		getGradeToExecute() const;

	protected:
		void		checkExecutionClearance(Bureaucrat const &executor) const;

	private:
		std::string const	_name;
		std::string const	_target;
		bool				_signed;
		Grade const			_gradeToSign;
		Grade const			_gradeToExecute;

		void		checkGrades() const;
};

std::ostream	&operator<<(std::ostream &os, AForm const &form);

#endif
