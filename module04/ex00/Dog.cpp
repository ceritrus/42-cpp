#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	this->type = "Dog";
	std::cout << "Constructor: Dog" << std::endl;
}

Dog::Dog(const Dog &input)
{
	this->type = input.type;
	std::cout << "Copy Constructor: " << this->type << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor: Dog" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Waf" << std::endl;
}

Dog& Dog::operator = (const Dog& right)
{
	this->type = right.type;
	return *this;
}