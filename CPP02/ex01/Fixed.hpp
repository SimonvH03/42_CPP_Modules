#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <iomanip>

void	announce(std::string const &name, std::string const &func);

class Fixed
{
	private:
	static const
		int	bitCount = 8;
		int	value;

	public:
		Fixed();
		Fixed(int const iValue);
		Fixed(float const fValue);
		Fixed(Fixed const &src);
		Fixed& operator=(Fixed const &src);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);

		float	toFloat() const;
		int		toInt() const;
};

#endif
