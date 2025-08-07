#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, short gradeToSign, short gradeToExecute);
		AForm(std::string name, std::string target, short gradeToSign, short gradeToExecute);
		AForm(AForm const &original);
		AForm &operator=(AForm const &original);
		virtual ~AForm();

		class GradeTooLowException: public std::exception
		{public:	const char *what() const throw();};
		class GradeTooHighException: public std::exception
		{public:	const char *what() const throw();};
		class FormNotSignedException: public std::exception
		{public:	const char *what() const throw();};

		virtual void	execute(Bureaucrat const &executor) const = 0;

		void		beSigned(Bureaucrat const &bureaucrat);

		std::string	getName() const;
		std::string	getTarget() const;
		bool		getSigned() const;
		short		getGradeToSign() const;
		short		getGradeToExecute() const;

	protected:
		void		checkExec(Bureaucrat const &executor) const;

	private:
		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const short			_gradeToSign;
		const short			_gradeToExecute;

		void		checkGrades() const;
};

std::ostream	&operator<<(std::ostream &os, AForm const &form);

#endif
