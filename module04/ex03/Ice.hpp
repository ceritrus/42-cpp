#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(Ice const &that);
    ~Ice();
    Ice & operator=(Ice const &that);

    AMateria *clone() const;
    void use(ICharacter & target);
};

#endif