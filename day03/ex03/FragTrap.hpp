#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

private:
	std::string _name;
	int _energyPoints;

protected:
	int _hitPoints;
	int _attackDamage;

public:
	void attack(const std::string& target);
	void highFivesGuys(void);
	void status();
};

#endif