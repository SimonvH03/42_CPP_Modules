#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, short gradeToSign, short gradeToExecute);
		Form(Form const &original);
		Form &operator=(Form const &original);
		~Form();

		class GradeTooLowException: public std::exception
		{public:	const char *what() const throw();};
		class GradeTooHighException: public std::exception
		{public:	const char *what() const throw();};

		void		beSigned(Bureaucrat const &bureaucrat);

		std::string	getName() const;
		bool		getSigned() const;
		short		getGradeToSign() const;
		short		getGradeToExecute() const;

	private:
		const std::string	_name;
		bool				_signed;
		const short			_gradeToSign;
		const short			_gradeToExecute;

		void		checkGrades() const;
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
