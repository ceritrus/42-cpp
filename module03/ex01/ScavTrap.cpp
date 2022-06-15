#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap initialized to default" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	std::cout << "ScavTrap " << _name << " initialized" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << " ScavTrap destroyed" << std::endl;
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
