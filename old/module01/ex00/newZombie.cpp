#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* zomb = new Zombie();
	zomb->setName(name);
	return zomb;
}