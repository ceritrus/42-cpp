#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap initialized to default" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap " << _name << " initialized" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destroyed "<< std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Diamond name: " << _name << std::endl;
	std::cout << "Clap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::status()
{
	std::cout << _name << " status:" << std::endl;
	std::cout << "\tHit points: " << _hitPoints << std::endl;
	std::cout << "\tEnergy points: "<< _energyPoints << std::endl;
}