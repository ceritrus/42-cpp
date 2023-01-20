#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap jeff("Jeff");
	ScavTrap alice("Alice");
	FragTrap martinez("Martinez");

	jeff.status();
	alice.status();
	martinez.status();
	std::cout << std::endl;

	jeff.attack("Martinez");
	martinez.attack("Jeff");
	jeff.takeDamage(30);
	std::cout << "Alice fell" << std::endl;
	alice.takeDamage(5);
	alice.status();
	alice.beRepaired(3);
	alice.status();
	martinez.highFivesGuys();
	std::cout << std::endl;


	jeff.status();
	alice.status();
	martinez.status();
	
	std::cout << std::endl << "# End of main #" << std::endl;
}