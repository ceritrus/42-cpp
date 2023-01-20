#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap & copy);
	~FragTrap();

	FragTrap & operator = (const FragTrap & rhs);

public:
	void highFivesGuys(void);
};
