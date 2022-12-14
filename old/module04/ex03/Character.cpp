#include "Character.hpp"

Character::Character()
    : _name("Bob"), _equipped(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(std::string const &name)
    : _name(name), _equipped(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(Character const &that)
    : _name(that._name), _equipped(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < that._equipped; i++)
        equip(that._inventory[i]->clone());
}

Character::~Character()
{
    for (int i = 0; i < _equipped; i++)
        delete _inventory[i];
}

Character & Character::operator=(Character const &that)
{
    for (int i = 0; i < _equipped; i++)
        delete _inventory[i];
    _equipped = 0;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < that._equipped; i++)
        equip(that._inventory[i]->clone());
    return *this;
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *materia)
{
    if (_equipped == 4 || materia == NULL)
        return ;
    for (int i = 0; i < _equipped; i++)
        if (_inventory[i] == materia)
            return ;
    _inventory[_equipped++] = materia;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= _equipped)
        return ;
    for (int i = idx; i < 3; i++)
    {
        _inventory[i] = _inventory[i + 1];
        _inventory[i + 1] = NULL;
    }
    _equipped--;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= _equipped)
        return ;
    std::cout << _name << " - ";
    _inventory[idx]->use(target);
}