#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap & copy);
	~ScavTrap();

	ScavTrap & operator = (const ScavTrap & rhs);

public:
	void guardGate();
	void attack(const std::string& target);
};