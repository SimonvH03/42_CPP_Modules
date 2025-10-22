#include <iostream>
#include "classes/AMateria.hpp"
#include "classes/Character.hpp"
#include "classes/Cure.hpp"
#include "classes/Ice.hpp"
#include "classes/ICharacter.hpp"
#include "classes/IMateriaSource.hpp"
#include "classes/MateriaSource.hpp"

int	main(void)
{
	AMateria		*icycle = new Ice();
	AMateria		*medicine = new Cure();
	IMateriaSource	*sorcerer = new MateriaSource();
	ICharacter		*Bob = new Character("Bob");
	ICharacter		*Jim = new Character("Jim");

	std::cout << "\n\e[32mour original AMaterias\e[0m\n";
	std::cout << icycle->getType() << "\n";
	std::cout << medicine->getType() << "\n";

	std::cout << "\n\e[32mcreating things we don't yet know about\e[0m\n";
	// creating things we don't yet know about
	sorcerer->createMateria("ice");
	sorcerer->createMateria("cure");

	std::cout << "\n\e[32madding too much to sorcerer's book\e[0m\n";
	// adding too much to sorcerer's book
	sorcerer->learnMateria(icycle);
	sorcerer->learnMateria(medicine);
	sorcerer->learnMateria(icycle);
	sorcerer->learnMateria(medicine);
	sorcerer->learnMateria(icycle);
	sorcerer->learnMateria(medicine);

	std::cout << "\n\e[32mwe don't have rocks\e[0m\n";
	// we don't have rocks
	sorcerer->createMateria("rock");

	std::cout << "\n\e[32mbadly unequiping stuff\e[0m\n";
	// badly unequiping stuff
	Bob->unequip(0);
	Jim->unequip(3);
	Bob->unequip(42);
	Jim->unequip(-1);

	std::cout << "\n\e[32musing things we don't have\e[0m\n";
	// using things we don't have
	Bob->use(0, *Jim);
	Bob->use(1, *Jim);
	Jim->use(2, *Bob);
	Jim->use(3, *Bob);

	AMateria	*ground[2];
	AMateria	*tmp;

	std::cout << "\n\e[32mfilling inventory and unequiping last slot\e[0m\n";
	// filling inventory and unequiping last slot
	Bob->equip(sorcerer->createMateria("ice"));
	Bob->equip(sorcerer->createMateria("cure"));
	Bob->equip(sorcerer->createMateria("ice"));
	tmp = sorcerer->createMateria("cure");
	Bob->equip(tmp);
	Bob->unequip(3);
	Bob->equip(tmp);

	std::cout << "\n\e[32mfilling inventory and unequiping second slot\e[0m\n";
	// filling inventory and unequiping second slot
	Jim->equip(sorcerer->createMateria("ice"));
	tmp = sorcerer->createMateria("cure");
	Jim->equip(tmp);
	Jim->equip(sorcerer->createMateria("cure"));
	Jim->equip(sorcerer->createMateria("ice"));
	Jim->unequip(1);
	Jim->equip(tmp);

	std::cout << "\n\e[32musing them thingies\e[0m\n";
	// using them thingies
	Bob->use(0, *Jim);
	Bob->use(1, *Jim);
	Jim->use(2, *Bob);
	Jim->use(3, *Bob);

	std::cout << "\n\e[32musing unequiped items/ bad indexes\e[0m\n";
	// using unequiped items/ bad indexes
	Bob->use(4, *Jim);
	Bob->use(42, *Jim);
	Bob->use(-1, *Jim);
	Jim->unequip(1);
	Jim->use(1, *Jim);
	Jim->equip(tmp);

	std::cout << "\n\e[32madding too much to inventory\e[0m\n";
	// adding too much to inventory
	tmp = sorcerer->createMateria("ice");
	Bob->equip(tmp);
	Jim->equip(tmp);
	ground[0] = tmp;
	tmp = sorcerer->createMateria("cure");
	Bob->equip(tmp);
	Jim->equip(tmp);
	ground[1] = tmp;

	std::cout << "\n\e[32mdone\e[0m\n";

	delete ground[0];
	delete ground[1];

	Character	test;
	test.equip(sorcerer->createMateria(icycle->getType()));
	Character	test1(test);
	test1.use(0, test);

	delete icycle;
	std::cout << "\n";
	delete medicine;
	std::cout << "\n";
	delete sorcerer;
	std::cout << "\n";
	delete Bob;
	std::cout << "\n";
	delete Jim;
}
