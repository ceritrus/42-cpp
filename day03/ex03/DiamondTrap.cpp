#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Diammy_clap_name"), FragTrap(), ScavTrap()
{
	#ifdef DEBUG
		std::cout << "\033[33m[DiamondTrap]\033[0m Default constructor called" << std::endl;
	#endif
	ClapTrap::_name = "Diammy_clap_name";
	this->_name = "Diammy";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	#ifdef DEBUG
		std::cout << "\033[33m[DiamondTrap]\033[0m Constructor called" << std::endl;
	#endif
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap & copy)
{
	#ifdef DEBUG
		std::cout << "\033[33m[DiamondTrap]\033[0m Copy constructor called" << std::endl;
	#endif
	this->_name = copy._name;
	this->ClapTrap::_name = copy.ClapTrap::_name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	#ifdef DEBUG
		std::cout << "\033[33m[DiamondTrap]\033[0m Destructor called" << std::endl;
	#endif
}

void DiamondTrap::whoAmI()
{
	std::cout << "Diamond name: " << this->_name << std::endl;
	std::cout << "Clap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::status()
{
	std::cout << _name << " - Status report:" << std::endl;
	std::cout << "\tHit points: " << _hitPoints << std::endl;
	std::cout << "\tEnergy points: "<< _energyPoints << std::endl;
}

// Operators

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & rhs)
{
	#ifdef DEBUG
		std::cout << "\033[33m[DiamondTrap]\033[0m Copy assignment operator called" << std::endl;
	#endif
	this->_name = rhs._name;
	this->ClapTrap::_name = rhs.ClapTrap::_name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}
