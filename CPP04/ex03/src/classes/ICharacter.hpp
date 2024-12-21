#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <iostream>

class ICharacter
{
	private:

	protected:

	public:
		ICharacter();
		ICharacter(ICharacter const &original);
		ICharacter &operator=(ICharacter const &original);
		~ICharacter();
};

#endif
