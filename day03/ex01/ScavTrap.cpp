#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	#ifdef DEBUG
		std::cout << "\033[33m[ScavTrap]\033[0m Default constructor called" << std::endl;
	#endif
	this->_name = "Scavvy";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	#ifdef DEBUG
		std::cout << "\033[33m[ScavTrap]\033[0m Constructor called" << std::endl;
	#endif
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap & copy)
{
	#ifdef DEBUG
		std::cout << "\033[33m[ScavTrap]\033[0m Copy constructor called" << std::endl;
	#endif
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}

ScavTrap::~ScavTrap()
{
	#ifdef DEBUG
		std::cout << "\033[33m[ScavTrap]\033[0m Destructor called" << std::endl;
	#endif
}

void ScavTrap::attack(const std::string& target)
{
	if (checkRessources())
		return;
	std::cout << _name << " violently shakes " << target;
	std::cout << ", causing " << _attackDamage << " damage!" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << _name << " is now in gatekeeper mode" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs)
{
	#ifdef DEBUG
		std::cout << "\033[33m[ScavTrap]\033[0m Copy assignment operator called" << std::endl;
	#endif
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}