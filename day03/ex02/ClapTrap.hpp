#pragma once
#include <iostream>

class ClapTrap
{
public:
	ClapTrap();	
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap & copy);
	~ClapTrap();

	ClapTrap & operator = (const ClapTrap & rhs);

protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void status();

protected:
	int checkRessources();
};