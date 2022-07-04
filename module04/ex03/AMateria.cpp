#include "AMateria.hpp"

AMateria::AMateria(const std::string & type) : _type(type) {}
AMateria::~AMateria() {};

std::string const & AMateria::getType() const
{
    return _type;
}