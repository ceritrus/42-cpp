#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Clapy"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	#ifdef DEBUG
		std::cout << "\033[33m[ClapTrap]\033[0m Default constructor called" << std::endl;
	#endif
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	#ifdef DEBUG
		std::cout << "\033[33m[ClapTrap]\033[0m Constructor called" << std::endl;
	#endif
}

ClapTrap::ClapTrap(const ClapTrap & copy)
{
	#ifdef DEBUG
		std::cout << "\033[33m[ClapTrap]\033[0m Copy constructor called" << std::endl;
	#endif
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}

ClapTrap::~ClapTrap()
{
	#ifdef DEBUG
		std::cout << "\033[33m[ClapTrap]\033[0m Destructor called" << std::endl;
	#endif
}

void ClapTrap::attack(const std::string& target)
{
	if (checkRessources())
		return;
	std::cout << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << _name << " took " << amount << " damage!" << std::endl;
	this->_hitPoints -= amount;
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
	std::cout << _name << " - Status report:" << std::endl;
	std::cout << "\tHit points: " << _hitPoints << std::endl;
	std::cout << "\tEnergy points: "<< _energyPoints << std::endl;
}

// Operators

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs)
{
	#ifdef DEBUG
		std::cout << "\033[33m[ClapTrap]\033[0m Copy assignment operator called" << std::endl;
	#endif
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}
