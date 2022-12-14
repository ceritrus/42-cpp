#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "lame stick";
}

Weapon::Weapon(std::string newType)
{
	type = newType;
}

Weapon::~Weapon()
{

}

const std::string& Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string newType)
{
	type = newType;
}