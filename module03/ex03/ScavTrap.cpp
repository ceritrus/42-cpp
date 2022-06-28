#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap(), _hitPoints(100), _attackDamage(20), _energyPoints(50)
{
	std::cout << "ScavTrap initialized to default" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name), _hitPoints(100), _attackDamage(20), _energyPoints(50)
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
	std::cout << _name << " is now in gatekeeper mode with " << _hitPoints << " hp" << std::endl;
}

void ScavTrap::status()
{
	std::cout << _name << " status:" << std::endl;
	std::cout << "\tHit points: " << _hitPoints << std::endl;
	std::cout << "\tEnergy points: "<< _energyPoints << std::endl;
}