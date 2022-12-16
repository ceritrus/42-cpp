#include "Zombie.hpp"

int main()
{
    Zombie* horde = zombieHorde(10, "Fred");
    for (int i = 0; i < 10; i++)
        horde[i].announce();
    delete[] horde; 
    std::cout << "End of main" << std::endl;
    return (0);
}