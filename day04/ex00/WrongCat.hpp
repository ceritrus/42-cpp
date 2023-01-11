#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& input);
	~WrongCat();

	WrongCat& operator = (const WrongCat& right);

public:
	void makeSound() const;
};

#endif