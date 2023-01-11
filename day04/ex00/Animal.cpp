#include "Animal.hpp"


Animal::Animal()
	: type("Animal")
{
	std::cout << "Constructor: Animal" << std::endl;
}

Animal::Animal(const Animal &input)
{
	this->type = input.type;
	std::cout << "Copy Constructor: " << this->type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor: Animal" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Unidentified animal sound" << std::endl;
}

Animal& Animal::operator = (const Animal& right)
{
	this->type = right.type;
	return *this;
}