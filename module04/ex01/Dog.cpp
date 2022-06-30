#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	std::cout << "Constructor: Dog" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Destructor: Dog" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << "Waf" << std::endl;
}