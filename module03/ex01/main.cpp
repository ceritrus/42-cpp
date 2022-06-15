#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap jeff("Jeff");
	ScavTrap alice("Alice");

	jeff.attack("Alice");
	alice.takeDamage(4);
	alice.beRepaired(2);
	jeff.takeDamage(8);
	alice.guardGate();
	jeff.status();
	alice.status();
}