#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();

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

#endif