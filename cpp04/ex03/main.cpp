#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

#include <iostream>

int main()
{   
   	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* moi = new Character("moi");
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	moi->equip(tmp);
	moi->unequip(3);
	tmp = src->createMateria("cure");
	moi->equip(tmp);

	ICharacter* bob = new Character("bob");
	
	std::cout << std::endl;
	moi->use(0, *bob);
	moi->use(1, *bob);

	moi->unequip(0);
	moi->use(0, *bob);
	moi->use(1, *bob);
	std::cout << std::endl;
	
	delete bob;
	delete moi;
	delete src;

	return 0;
}

