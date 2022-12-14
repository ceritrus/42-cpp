#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	{
		Zombie jeff("Jeff");
		jeff.announce();
	}

	randomChump("Ronald");

	Zombie* copernicus = newZombie("Copernicus");
	copernicus->announce();
	delete copernicus;
}