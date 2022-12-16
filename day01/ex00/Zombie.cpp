#include "Zombie.hpp"

Zombie::Zombie() : m_name("Default")
{
    #ifdef DEBUG
        std::cout << "\033[33m[Zombie]\033[0m Default constructor called" << std::endl;
    #endif
}

Zombie::Zombie(std::string name) : m_name(name)
{
    #ifdef DEBUG
        std::cout << "\033[33m[Zombie]\033[0m " << this->m_name << " : initialized" << std::endl;
    #endif
}

Zombie::~Zombie()
{
    #ifdef DEBUG
        std::cout << "\033[33m[Zombie]\033[0m " << this->m_name << " : destroyed" << std::endl;
    #endif
}

void Zombie::setName(std::string name)
{
    this->m_name = name;
}

std::string Zombie::getName()
{
    return this->m_name;
}

void Zombie::announce()
{
    std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


