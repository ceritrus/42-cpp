#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL)
{
    #ifdef DEBUG
        std::cout << "\033[33m[HumanB]\033[0m " << m_name << " : initialized" << std::endl;
    #endif
}

HumanB::~HumanB()
{
    #ifdef DEBUG
        std::cout << "\033[33m[HumanB]\033[0m " << m_name << " : destroyed" << std::endl;
    #endif
}

void HumanB::setWeapon(Weapon &weapon)
{
    m_weapon = &weapon;
}

void HumanB::attack()
{
    std::cout << m_name << " attacks with " << m_weapon->getType() << std::endl;
}
