#include "Zombie.hpp"

int main()
{
    Zombie* zombie = newZombie("Adam");
    zombie->announce();
    delete zombie;
    randomChump("Eve");
    std::cout << "End of main" << std::endl;
    return (0);
}