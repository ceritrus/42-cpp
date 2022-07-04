#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("Roger");

	AMateria* tmp = NULL;
	AMateria* first = NULL;
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	first = tmp;
	me->equip(tmp); // 0
	tmp = src->createMateria("cure");
	me->equip(tmp); // 1
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp); // 2
	tmp = src->createMateria("ice");
	me->equip(tmp); // 3
	tmp = src->createMateria("ice");
	me->equip(tmp); 
	delete tmp;
	me->equip(NULL);

	ICharacter* bob = new Character("Bob");
	me->use(-1, *bob); // none
	me->use(0, *bob); // ice
	me->use(1, *bob); // cure
	me->use(2, *bob); // cure
	me->use(3, *bob); // ice
	me->use(4, *bob); // none

	me->unequip(0);
	me->use(0, *bob); // cure
	me->use(3, *bob); // none
	me->unequip(-1); // none
	me->equip(first); // 3

    ICharacter* harmony = new Character("Harmony");
    me->use(3, *harmony);
    tmp = src->createMateria("cure");
    harmony->equip(tmp);
    harmony->use(0, *me);

	delete bob;
	delete me;
    delete harmony;
	delete src;

	return (0);
}