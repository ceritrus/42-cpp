#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal& input);
	virtual ~Animal();

	Animal& operator = (const Animal& right);

protected:
	std::string type;

public:
	virtual void makeSound() const;
	std::string getType() const;
};

#endif