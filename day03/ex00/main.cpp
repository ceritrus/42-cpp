#include "ClapTrap.hpp"

int main()
{
	ClapTrap jeff("Jeff");
	ClapTrap alice("Alice");

	jeff.attack("Alice");
	alice.takeDamage(4);
	alice.beRepaired(3);
	alice.beRepaired(3);
	alice.status();
	std::cout << std::endl;

	alice.attack("Jeffrey");
	jeff.takeDamage(0);
	jeff.status();
	std::cout << std::endl;

	std::cout << "Jeff = Alice" << std::endl;
	jeff = alice;
	jeff.status();
	std::cout << std::endl << "# End of main #" << std::endl;
}