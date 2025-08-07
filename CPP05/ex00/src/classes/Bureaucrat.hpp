#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, short grade);
		Bureaucrat(Bureaucrat const &original);
		Bureaucrat &operator=(Bureaucrat const &original);
		~Bureaucrat();

		static const	short	UpperBound = 1;
		static const	short	LowerBound = 150;

		class GradeTooHighException: public std::exception
		{public:	const char *what() const throw();};
		class GradeTooLowException: public std::exception
		{public:	const char *what() const throw();};

		void		incrementGrade();
		void		decrementGrade();

		std::string	getName() const;
		short		getGrade() const;

	private:
		const std::string	_name;
		short				_grade;

		void		checkGrade() const;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
