#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap & copy);
	~DiamondTrap();

	DiamondTrap & operator = (const DiamondTrap & rhs);

private:
	std::string _name;
	using FragTrap::_hitPoints;
	using ScavTrap::_energyPoints;
	using FragTrap::_attackDamage;

public:
	void whoAmI(void);
	using ScavTrap::attack;
	void status();
};
