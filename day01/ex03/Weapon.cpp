#include "Weapon.hpp"

Weapon::Weapon() : m_type("Default")
{
    #ifdef DEBUG
        std::cout << "\033[33m[Weapon]\033[0m Default constructor called" << std::endl;
    #endif
}

Weapon::Weapon(std::string type) : m_type(type)
{
    #ifdef DEBUG
        std::cout << "\033[33m[Weapon]\033[0m " << m_type << " : initialized" << std::endl;
    #endif
}

Weapon::~Weapon()
{
    #ifdef DEBUG
        std::cout << "\033[33m[Weapon]\033[0m " << m_type << " : destroyed" << std::endl;
    #endif
}

void Weapon::setType(std::string type)
{
    this->m_type = type;
}

std::string const &Weapon::getType()
{
    return this->m_type;
}