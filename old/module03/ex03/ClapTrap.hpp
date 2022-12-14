#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();

protected:
	std::string _name;

private:
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

#endif