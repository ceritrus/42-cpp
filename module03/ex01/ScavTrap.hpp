#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();

private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	void attack(const std::string& target);
	void guardGate();

private:
	int checkRessources();
};

#endif