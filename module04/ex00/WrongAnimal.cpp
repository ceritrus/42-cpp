#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
	: type("WrongAnimal")
{
	std::cout << "Constructor: WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &input)
{
	this->type = input.type;
	std::cout << "Copy Constructor: " << this->type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor: WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Unidentified wrong animal sound" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& right)
{
	this->type = right.type;
	return *this;
}