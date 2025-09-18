#ifndef GRADE_HPP
# define GRADE_HPP

class Grade
{
	public:
		Grade();
		Grade(int grade);
		Grade(Grade const &original);
		Grade &operator=(Grade const &original);
		~Grade();

		static const int	LowerBound = 150;
		static const int	UpperBound = 1;

		bool	operator<(Grade const &other) const;
		bool	operator>(Grade const &other) const;
		bool	operator<(int n) const;
		bool	operator>(int n) const;
		Grade	&operator++();
		Grade	&operator--();

		operator int() const;

	private:
		int	_grade;
};

#endif
