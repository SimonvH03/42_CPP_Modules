#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>

class Character
{
	private:

	protected:

	public:
		Character();
		Character(Character const &original);
		Character &operator=(Character const &original);
		~Character();
};

#endif
