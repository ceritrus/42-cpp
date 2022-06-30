#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	std::cout << "Constructor: Cat" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Destructor: Cat" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}