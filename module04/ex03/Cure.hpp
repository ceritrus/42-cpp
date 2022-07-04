#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(Cure const &that);
    ~Cure();
    Cure & operator=(Cure const &that);

    AMateria *clone() const;
    void use(ICharacter & target);
};

#endif