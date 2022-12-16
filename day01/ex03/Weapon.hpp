#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
private:
    std::string m_type;
public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    void setType(std::string type);
    std::string const &getType();
};

#endif