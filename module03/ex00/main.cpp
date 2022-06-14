#include "ClapTrap.hpp"

int main()
{
	ClapTrap jeff("Jeff");
	ClapTrap alice("Alice");

	jeff.attack("Alice");
	alice.takeDamage(4);
	alice.beRepaired(2);
	jeff.takeDamage(8);
	jeff.status();
	alice.status();
}