#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <iomanip>

class Fixed
{
	private:
	static const
		int	bitCount = 8;

		int	numberValue;
		void	announce(std::string const &name, std::string const &func) const;

	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed& operator=(Fixed const &src);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif
