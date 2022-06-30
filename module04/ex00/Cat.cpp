#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	this->type = "Cat";
	std::cout << "Constructor: Cat" << std::endl;
}

Cat::Cat(const Cat &input)
{
	this->type = input.type;
	std::cout << "Copy Constructor: " << this->type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor: Cat" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Cat& Cat::operator = (const Cat& right)
{
	this->type = right.type;
	return *this;
}