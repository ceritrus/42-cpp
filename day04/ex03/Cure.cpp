#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &that) : AMateria(that.getType()) {}

Cure::~Cure() {}

Cure & Cure::operator=(Cure const &that)
{
    _type = that.getType();
    return *this;
}

AMateria * Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}