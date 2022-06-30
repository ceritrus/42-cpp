#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


void talk(const Animal* beast)
{
	std::cout << beast->getType() << ": ";
	beast->makeSound();
	delete beast;
	std::cout << "- - - - - - - - -" << std::endl;
}

int main()
{
	Animal* meta = new Animal();
	talk(meta);
	Dog* dog = new Dog();
	talk(dog);
	Cat* cat = new Cat();
	talk(cat);
}