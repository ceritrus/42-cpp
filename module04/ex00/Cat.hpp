#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& input);
	~Cat();

	Cat& operator = (const Cat& right);

public:
	void makeSound() const;
};

#endif