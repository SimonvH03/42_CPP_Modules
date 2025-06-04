#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const short			_gradeToSign;
		const short			_gradeToExecute;
		bool				_signed;
		void				checkGrades(void) const;

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

		std::string	getName(void) const;
		bool		getSigned(void) const;
		short		getGradeToSign(void) const;
		short		getGradeToExecute(void) const;

};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
