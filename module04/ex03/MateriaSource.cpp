#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
    : amount(0)
{
    for (int i = 0; i < 4; i++)
        sources[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &that)
    : amount(0)
{
    for (int i = 0; i < 4; i++)
        sources[i] = NULL;
    for (int i = 0; i < that.amount; i++)
        learnMateria(that.sources[i]->clone());
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete sources[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const &that)
{
    for (int i = 0; i < amount; i++)
        delete sources[i];
    amount = 0;
    for (int i = 0; i < 4; i++)
        sources[i] = NULL;
    for (int i = 0; i < that.amount; i++)
        learnMateria(that.sources[i]->clone());
    return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (amount == 4 || materia == NULL)
        return ;
    for (int i = 0; i < amount; i++)
        if (sources[i] == materia)
            return ;
    sources[amount++] = materia; 
}

AMateria * MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < amount; i++)
        if (sources[i]->getType() == type)
            return sources[i]->clone();
    return NULL;
}