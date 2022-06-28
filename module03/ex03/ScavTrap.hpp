#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();

private:
	std::string _name;
	int _hitPoints;
	int _attackDamage;

protected:
	int _energyPoints;
	void attack(const std::string& target);

public:
	void guardGate();
	void status();
};

#endif