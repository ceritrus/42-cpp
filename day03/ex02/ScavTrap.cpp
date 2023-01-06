#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap(), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ScavTrap initialized to default" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	_name = name;
	std::cout << "ScavTrap " << _name << " initialized" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed "<< std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (checkRessources())
		return;
	std::cout << _name << " violently shakes " << target;
	std::cout << ", causing " << _attackDamage << " damage! Nice!" << std::endl;
	_energyPoints -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << _name << " is now in gatekeeper mode" << std::endl;
}

int ScavTrap::checkRessources()
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

void ScavTrap::status()
{
	std::cout << _name << " status:" << std::endl;
	std::cout << "\tHit points: " << _hitPoints << std::endl;
	std::cout << "\tEnergy points: "<< _energyPoints << std::endl;
}