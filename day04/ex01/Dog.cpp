#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	std::cout << "Constructor: Dog" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &input)
{
	std::cout << "Copy Constructor: Dog" << type << std::endl;
	type = input.type;
	brain = new Brain(*input.brain);
}

Dog::~Dog()
{
	std::cout << "Destructor: Dog" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Waf" << std::endl;
}

Dog& Dog::operator = (const Dog& right)
{
	std::cout << "Copy Assignment Operator: Dog" << std::endl;
	type = right.type;
	*brain = *right.brain;
	return *this;
}

void Dog::think(std::string idea)
{
	brain->think(idea);
}

void Dog::remember()
{
	std::cout << "Dog remembers:" << std::endl;
	brain->remember();
}