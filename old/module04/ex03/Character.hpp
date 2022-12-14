#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    int _equipped;
    AMateria *_inventory[4];

public:
    Character();
    Character(std::string const &name);
    Character(Character const &that);
    ~Character();
    Character &operator=(Character const &that);

    std::string const &getName() const;
    void equip(AMateria* materia);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif