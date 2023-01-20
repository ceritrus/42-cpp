#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	#ifdef DEBUG
		std::cout << "\033[33m[FragTrap]\033[0m Default constructor called" << std::endl;
	#endif
	this->_name = "Fraggy";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	#ifdef DEBUG
		std::cout << "\033[33m[FragTrap]\033[0m Constructor called" << std::endl;
	#endif
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap & copy)
{
	#ifdef DEBUG
		std::cout << "\033[33m[FragTrap]\033[0m Copy constructor called" << std::endl;
	#endif
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}

FragTrap::~FragTrap()
{
	#ifdef DEBUG
		std::cout << "\033[33m[FragTrap]\033[0m Destructor called" << std::endl;
	#endif
}

void FragTrap::highFivesGuys(void)
{
	std::cout << _name << " is requesting a highfive!" << std::endl;
}