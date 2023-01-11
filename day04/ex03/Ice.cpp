#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &that) : AMateria(that.getType()) {}

Ice::~Ice() {}

Ice & Ice::operator=(Ice const &that)
{
    _type = that.getType();
    return *this;
}

AMateria * Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}