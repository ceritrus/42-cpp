#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& input);
	~Dog();

	Dog& operator = (const Dog& right);

private:
	Brain* brain;

public:
	void makeSound() const;
	void think(std::string idea);
	void remember();
};

#endif