#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap gem("Gem");
	gem.attack("a random guy");
	gem.status();
	gem.takeDamage(5);
	gem.guardGate();
	gem.highFivesGuys();
	gem.beRepaired(3);
	gem.status();
	gem.whoAmI();
}