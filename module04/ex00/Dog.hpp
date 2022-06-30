#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& input);
	~Dog();

	Dog& operator = (const Dog& right);
public:
	void makeSound() const;
};

#endif