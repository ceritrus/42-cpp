#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diam("Diam");

	diam.status();
	std::cout << std::endl;

	diam.attack("a random guy");
	diam.guardGate();
	diam.highFivesGuys();
	std::cout << std::endl;
	
	diam.status();
	std::cout << std::endl;
	
	diam.whoAmI();

	std::cout << std::endl << "# End of main #" << std::endl;
}