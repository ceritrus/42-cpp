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
	jeff.takeDamage(30);
	std::cout << "Alice fell" << std::endl;
	alice.takeDamage(5);
	alice.beRepaired(3);
	martinez.highFivesGuys();

	jeff.status();
	alice.status();
	martinez.status();
}