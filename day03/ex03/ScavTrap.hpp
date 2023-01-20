#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap & copy);
	~ScavTrap();

	ScavTrap & operator = (const ScavTrap & rhs);

private:
	std::string _name;

public:
	void guardGate();
	void attack(const std::string& target);
};