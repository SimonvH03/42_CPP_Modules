#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

# include "Grade.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, Grade gradeToSign, Grade gradeToExecute);
		Form(Form const &original);
		Form &operator=(Form const &original);
		~Form();

		class GradeTooHighException: public std::exception
		{public:	const char *what() const throw();};
		class GradeTooLowException: public std::exception
		{public:	const char *what() const throw();};

		void		beSigned(Bureaucrat const &bureaucrat);

		std::string	getName() const;
		bool		getSigned() const;
		Grade		getGradeToSign() const;
		Grade		getGradeToExecute() const;

	private:
		std::string const	_name;
		bool				_signed;
		Grade const			_gradeToSign;
		Grade const			_gradeToExecute;

		void		checkGrades() const;
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
