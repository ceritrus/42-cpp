#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& input);
	~Cat();

	Cat& operator = (const Cat& right);

private:
	Brain* brain;

public:
	void makeSound() const;
	void think(std::string idea);
	void remember();
};

#endif