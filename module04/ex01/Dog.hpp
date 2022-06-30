#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
public:
	Dog();
	~Dog();

private:
	Brain* brain;

public:
	void makeSound() const;
};

#endif