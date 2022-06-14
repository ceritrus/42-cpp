#include <iostream>

class ClapTrap
{
public:
	ClapTrap(std::string name);
	~ClapTrap();

private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};