#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    int amount;
    AMateria *sources[4];

public:
    MateriaSource();
    MateriaSource(MateriaSource const &that);
    ~MateriaSource();
    MateriaSource &operator= (MateriaSource const &that);

    void learnMateria(AMateria *materia);
    AMateria *createMateria(std::string const &type);
};

#endif