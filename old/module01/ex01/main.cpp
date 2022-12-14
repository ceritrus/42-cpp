#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int n = 8;
	Zombie* horde = zombieHorde(n, "Jeffrey Bezos");
	for (int i = 0; i < n; i++)
	{
		std::cout << i << ". ";
		horde[i].announce();
	}
	delete[] horde;
}