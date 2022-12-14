#include <iostream>

class ClapTrap
{
public:
	ClapTrap(std::string name);
	~ClapTrap();

private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void status();

private:
	int checkRessources();
};