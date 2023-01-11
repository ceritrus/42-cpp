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
	cat = new Cat();
	cat->think("Hello, I am a cat");
	cat->think("I like to sleep and eat fish");
	Cat* cat2 = new Cat(*cat);
	delete cat;
	cat2->remember();
	delete cat2;
}