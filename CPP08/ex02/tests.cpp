#include "TestCreation.hpp"
#include "ValidationTools.hpp"

#include "MutantStack.hpp"

#include <list>

TEST(Call_Default_Constructor) {
	MutantStack<int>	mutant;
}

TEST(Call_Copy_Constructor) {
	MutantStack<int>	mutant;
	MutantStack<int>	copy(mutant);
}

TEST(Call_Move_Constructor) {
	MutantStack<int>	mutant;
	MutantStack<int>	copy(std::move(mutant));
}

TEST(Call_Stack_Copy_Constructor1) {
	MutantStack<int>	mutant;
	std::stack<int>		copy(mutant);
}

TEST(Call_Stack_Copy_Constructor2) {
	std::stack<int>		stack;
	MutantStack<int>	copy(stack);
}

TEST(Call_Stack_Move_Constructor1) {
	MutantStack<int>	mutant;
	std::stack<int>		copy(std::move(mutant));
}

TEST(Call_Stack_Move_Constructor2) {
	std::stack<int>		stack;
	MutantStack<int>	copy(std::move(stack));
}

TEST(Call_Emplace) {
	MutantStack<int>	mutant;
	mutant.emplace();
}

TEST(Call_Empty) {
	{	MutantStack<int>		mutant;
		(void)mutant.empty();
	}
	{	MutantStack<int> const	mutant;
		(void)mutant.empty();
	}
}

TEST(Call_Pop) {
	MutantStack<int>	mutant;
	mutant.pop();
}

TEST(Call_Push) {
	MutantStack<int>	mutant;
	mutant.push(42);
}

TEST(Call_Size) {
	{	MutantStack<int>		mutant;
		(void)mutant.size();
	}
	{	MutantStack<int> const	mutant;
		(void)mutant.size();
	}
}

TEST(Call_Swap) {
	MutantStack<int>	mutant1;
	MutantStack<int>	mutant2;
	mutant1.swap(mutant2);
}

TEST(Call_Top) {
	{	MutantStack<int>		mutant;
		(void)mutant.top();
	}
	{	MutantStack<int> const	mutant;
		(void)mutant.top();
	}
}

TEST(Call_Begin) {
	{	MutantStack<int>		mutant;
		mutant.begin();
	}
	{	MutantStack<int> const	mutant;
		mutant.begin();
	}
}

TEST(Call_End) {
	{	MutantStack<int>		mutant;
		mutant.end();
	}
	{	MutantStack<int> const	mutant;
		mutant.end();
	}
}

TEST(Increment_Decrement_Iterator) {
	{	MutantStack<int>			mutant;
		MutantStack<int>::iterator	iter = mutant.begin();
		++iter;
		--iter;
	}
}

TEST(Dereference_Iterator_Begin) {
	{	MutantStack<int>	mutant;
		(void)*mutant.begin();
	}
}

TEST(Dereference_Iterator_End) {
	{	MutantStack<int>	mutant;
		(void)*mutant.end();
	}
}

TEST(Valid_Begin_Read) {
	{	MutantStack<int>	mutant;
		mutant.push(42);
		CHECK(*mutant.begin() == 42);
	}
}

TEST(Valid_End_Read) {
	{	MutantStack<int>	mutant;
		mutant.push(42);
		CHECK(*(mutant.end() - 1) == 42);
	}
}

TEST(Call_Begin_Write) {
	{	MutantStack<int>	mutant;
		mutant.push(0);
		*mutant.begin() = 42;
	}
}

TEST(Call_End_Write) {
	{	MutantStack<int>	mutant;
		mutant.push(0);
		*(mutant.end() - 1) = 42;
	}
}

TEST(Valid_Begin_Write) {
	{	MutantStack<int>	mutant;
		mutant.push(0);
		*mutant.begin() = 42;
		CHECK(*mutant.begin() == 42);
	}
}

TEST(Valid_End_Write) {
	{	MutantStack<int>	mutant;
		mutant.push(0);
		*(mutant.end() - 1) = 42;
		CHECK(*(mutant.end() - 1) == 42);
	}
}

TEST(Comparison_List1) {
	MutantStack<int>	mutant;
	std::list<int>		list;

	mutant.push(5);
	mutant.push(17);
	list.push_back(5);
	list.push_back(17);
	EQUATE(mutant.top(), list.back());
	mutant.pop();
	list.erase((--list.end()));
	EQUATE(mutant.size(), list.size());
}

TEST(Comparison_list2) {
	MutantStack<int>	mutant;
	std::list<int>		list;

	mutant.push(3);
	mutant.push(5);
	mutant.push(737);
	mutant.push(0);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	MutantStack<int>::iterator	mIter = mutant.begin();
	MutantStack<int>::iterator	mEnd = mutant.end();
	std::list<int>::iterator	lIter = list.begin();
	while (mIter < mEnd)
	{
		EQUATE(*mIter, *lIter);
		++mIter;
		++lIter;
	}
	MutantStack<int>::const_iterator	mIterConst = mutant.begin();
	MutantStack<int>::const_iterator	mEndConst = mutant.end();
	lIter = list.begin();
	while (mIterConst < mEndConst)
	{
		EQUATE(*mIterConst, *lIter);
		++mIterConst;
		++lIter;
	}
}
