#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include <iostream>

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &original);
		Cat &operator=(Cat const &original);
		~Cat();

		void	makeSound() const;
};

#endif
