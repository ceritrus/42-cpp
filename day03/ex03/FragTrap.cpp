#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap(), _energyPoints(100), _hitPoints(100), _attackDamage(30)
{
	std::cout << "FragTrap initialized to default" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name), _energyPoints(100), _hitPoints(100), _attackDamage(30)
{
	_name = name;
	std::cout << "FragTrap " << _name << " initialized" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed "<< std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (checkRessources())
		return;
	std::cout << _name << " violently shakes " << target;
	std::cout << ", causing " << _attackDamage << " damage! Nice!" << std::endl;
	_energyPoints -= 1;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << _name << " is requesting a highfive!" << std::endl;
}

void FragTrap::status()
{
	std::cout << _name << " status:" << std::endl;
	std::cout << "\tHit points: " << _hitPoints << std::endl;
	std::cout << "\tEnergy points: "<< _energyPoints << std::endl;
}
