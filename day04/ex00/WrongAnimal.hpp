#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& input);
	virtual ~WrongAnimal();

	WrongAnimal& operator = (const WrongAnimal& right);

protected:
	std::string type;

public:
	virtual void makeSound() const;
	std::string getType() const;
};

#endif