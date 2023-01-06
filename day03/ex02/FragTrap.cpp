#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap(), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	std::cout << "FragTrap initialized to default" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name), _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
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

int FragTrap::checkRessources()
{
	if (_hitPoints <= 0)
	{
		std::cout << _name << ": not enough hit points to perform action!" << std::endl;
		return 1;
	}
	if (_energyPoints <= 0)
	{
		std::cout << _name << ": not enough energy points to perform action!" << std::endl;
		return 1;
	}
	return 0;
}

void FragTrap::status()
{
	std::cout << _name << " status:" << std::endl;
	std::cout << "\tHit points: " << _hitPoints << std::endl;
	std::cout << "\tEnergy points: "<< _energyPoints << std::endl;
}