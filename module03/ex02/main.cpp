#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap jeff("Jeff");
	ScavTrap alice("Alice");
	FragTrap martinez("Martinez");


	jeff.attack("Martinez");
	martinez.attack("Jeff");
	jeff.takeDamage(8);
	std::cout << "Alice fell" << std::endl;
	alice.takeDamage(4);
	alice.beRepaired(2);
	martinez.highFivesGuys();

	jeff.status();
	alice.status();
	martinez.status();
}