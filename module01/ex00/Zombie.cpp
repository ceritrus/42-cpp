#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string newName)
	: name(newName)
{
	
}

Zombie::~Zombie()
{
	std::cout << name << " is no more" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string newName)
{
	name = newName;
}