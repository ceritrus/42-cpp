#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	std::cout << "Constructor: Cat" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &input)
{
	std::cout << "Copy Constructor: Cat" << std::endl;
	type = input.type;
	brain = new Brain(*input.brain);
}

Cat::~Cat()
{
	std::cout << "Destructor: Cat" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Cat& Cat::operator = (const Cat& right)
{
	std::cout << "Copy Assignment Operator: Cat" << std::endl;
	type = right.type;
	*brain = *right.brain;
	return *this;
}

void Cat::think(std::string idea)
{
	brain->think(idea);
}

void Cat::remember()
{
	std::cout << "Cat remembers:" << std::endl;
	brain->remember();
}