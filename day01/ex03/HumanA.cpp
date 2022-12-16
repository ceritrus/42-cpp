#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : m_name(name), m_weapon(weapon)
{
    #ifdef DEBUG
        std::cout << "\033[33m[HumanA]\033[0m " << m_name << " : initialized" << std::endl;
    #endif
}

HumanA::~HumanA()
{
    #ifdef DEBUG
        std::cout << "\033[33m[HumanA]\033[0m " << m_name << " : destroyed" << std::endl;
    #endif
}

void HumanA::attack()
{
    std::cout << m_name << " attacks with " << m_weapon.getType() << std::endl;
}
