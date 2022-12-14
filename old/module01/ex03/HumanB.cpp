#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
	: name(newName), weapon(NULL)
{
	
}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with their bare fists" << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}