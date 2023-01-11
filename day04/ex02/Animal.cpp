#include "Animal.hpp"


Animal::Animal()
	: type("Animal")
{
	std::cout << "Constructor: Animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor: Animal" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}