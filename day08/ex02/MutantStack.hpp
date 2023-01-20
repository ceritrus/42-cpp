#pragma once
#include <stack>
#include <iostream>

template <typename Type>
class MutantStack : public std::stack<Type>
{
public:
	MutantStack()
	{
		#ifdef DEBUG
			std::cout << "\033[33m[MutantStack]\033[0m Default constructor called" << std::endl;
		#endif
	};
	MutantStack(const MutantStack & copy)
	{
		#ifdef DEBUG
			std::cout << "\033[33m[MutantStack]\033[0m Copy constructor called" << std::endl;
		#endif
		*this = copy;
	};
	~MutantStack()
	{
		#ifdef DEBUG
			std::cout << "\033[33m[MutantStack]\033[0m Destructor called" << std::endl;
		#endif
	};
	MutantStack & operator = (const MutantStack & rhs)
	{
		#ifdef DEBUG
			std::cout << "\033[33m[MutantStack]\033[0m Copy assignment operator constructor called" << std::endl;
		#endif
		this->c = rhs.c;
		return *this;
	};

	typedef typename std::stack<Type>::container_type::iterator iterator;

	iterator begin()
	{
		return (this->c.begin());
	};

	iterator end()
	{
		return (this->c.end());
	};
};