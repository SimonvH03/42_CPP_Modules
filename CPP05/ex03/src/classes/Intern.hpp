#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <functional>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &original);
		Intern &operator=(Intern const &original);
		~Intern();

		class FormNotFoundException: public std::exception
		{public:	const char *what() const throw();};

		AForm	*makeForm(std::string formName, std::string target) const;

	private:
		struct FormTableEntry
		{
			std::string									name;
			std::function<AForm*(const std::string&)>	make;
		};
};

#endif
