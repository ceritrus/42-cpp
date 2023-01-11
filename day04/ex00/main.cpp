#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void talk(const Animal* beast)
{
	std::cout << beast->getType() << ": ";
	beast->makeSound();
	delete beast;
	std::cout << "- - - - - - - - -" << std::endl;
}

void wrong_talk(const WrongAnimal* beast)
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
	WrongAnimal* bad_meta = new WrongAnimal();
	wrong_talk(bad_meta);
	WrongCat* bad_cat = new WrongCat();
	wrong_talk(bad_cat);
}