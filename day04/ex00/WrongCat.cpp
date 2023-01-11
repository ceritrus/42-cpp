#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "Constructor: WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &input)
{
	this->type = input.type;
	std::cout << "Copy Constructor: " << this->type << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor: WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meaouf~ something went wrong here" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& right)
{
	this->type = right.type;
	return *this;
}