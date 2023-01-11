#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal();
	virtual ~Animal();

protected:
	std::string type;

public:
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif