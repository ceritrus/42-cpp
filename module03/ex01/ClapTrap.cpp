#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
	: _name("Nameless"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ClapTrap initialized to default" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ClapTrap "<< _name << " initialized" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (checkRessources())
		return;
	std::cout << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " damage!" << std::endl;
	_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << _name << " took " << amount << " damage!" << std::endl;
	_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (checkRessources())
		return;
	std::cout << _name << " repaired for " << amount << " hit points!" << std::endl;
	_hitPoints+= amount;
	_energyPoints--;
}

int ClapTrap::checkRessources()
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

void ClapTrap::status()
{
	std::cout << _name << " status:" << std::endl;
	std::cout << "\tHit points: " << _hitPoints << std::endl;
	std::cout << "\tEnergy points: "<< _energyPoints << std::endl;
}
