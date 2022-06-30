#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
public:
	Cat();
	~Cat();

private:
	Brain* brain;

public:
	void makeSound() const;
};

#endif