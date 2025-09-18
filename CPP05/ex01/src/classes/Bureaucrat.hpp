#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

# include "Grade.hpp"
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, Grade grade);
		Bureaucrat(Bureaucrat const &original);
		Bureaucrat &operator=(Bureaucrat const &original);
		~Bureaucrat();

		class GradeTooHighException: public std::exception
		{public:	const char *what() const throw();};
		class GradeTooLowException: public std::exception
		{public:	const char *what() const throw();};

		void		signForm(Form &form) const;

		void		incrementGrade();
		void		decrementGrade();

		std::string	getName() const;
		Grade		getGrade() const;

	private:
		std::string const	_name;
		Grade				_grade;

		void		checkGrade() const;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
