#include "Grade.hpp"

Grade::Grade()
	:	_grade(LowerBound)
{}

Grade::Grade(int grade)
	:	_grade(grade)
{}

Grade::Grade(Grade const &original)
	:	_grade(original._grade)
{}

Grade &Grade::operator=(Grade const &original)
{
	if (this != &original)
	{
		_grade = original._grade;
	}
	return (*this);
}

Grade::~Grade()
{}

bool	Grade::operator<(Grade const &other) const
{
	return (_grade > other._grade);
}

bool	Grade::operator>(Grade const &other) const
{
	return (_grade < other._grade);
}

bool	Grade::operator<(int n) const
{
	return (_grade > n);
}

bool	Grade::operator>(int n) const
{
	return (_grade < n);
}

Grade	&Grade::operator++()
{
	--_grade;
	return (*this);
}

Grade	&Grade::operator--()
{
	++_grade;
	return (*this);
}

Grade::operator int() const
{
	return (_grade);
}
