#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap jeff("Jeff");
	ScavTrap alice("Alice");

	jeff.status();
	alice.status();
	std::cout << std::endl;

	jeff.attack("Alice");
	alice.takeDamage(4);
	alice.beRepaired(2);
	alice.beRepaired(2);

	alice.attack("Jeff");
	jeff.takeDamage(8);
	alice.guardGate();

	std::cout << std::endl;
	jeff.status();
	alice.status();

	std::cout << std::endl << "# End of main #" << std::endl;
}