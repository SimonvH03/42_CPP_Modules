#include "Character.hpp"

Character::Character()
{
	name = "nameless";
	std::cout << "Character Default Constructor\n";
	for (int i = 0; i < INVENTORY_CAPACITY; i++)
		inventory[i] = NULL;
}

Character::Character(std::string _name)
{
	name = _name;
	std::cout << "Character Default Constructor\n";
	for (int i = 0; i < INVENTORY_CAPACITY; i++)
		inventory[i] = NULL;
}

Character::Character(Character const &original)
{
	std::cout << "Character Copy Constructor\n";
	for (int i = 0; i < INVENTORY_CAPACITY; i++)
		inventory[i] = NULL;
	*this = original;
}

Character &Character::operator=(Character const &original)
{
	std::cout << "Character Assignment Operator\n";
	if (this != &original)
	{
		for (int i = 0; i < INVENTORY_CAPACITY; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (original.inventory[i])
				inventory[i] = original.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character Destructor\n";
	for (int i = 0; i < INVENTORY_CAPACITY; i++)
		if (inventory[i])
			delete inventory[i];
}

int
Character::getInventoryUsage()
const
{
	int	slots;
	
	slots = 0;
	while (slots < INVENTORY_CAPACITY && inventory[slots])
		slots++;
	return (slots);
}

void
Character::equip(AMateria *materia)
{
	const int	i = getInventoryUsage();

	if (i == INVENTORY_CAPACITY)
		return ;
	inventory[i] = materia;
	std::cout << "Equiped AMateria " << materia->getType() << " in slot [" << i << "]\n";
}

void
Character::unequip(int index)
{
	if (index < 0 || index >= INVENTORY_CAPACITY)
		return ;
	if (inventory[index])
	{
		inventory[index] = NULL;
		std::cout << "Unequiped AMateria in slot [" << index << "]\n";
	}
}

void
Character::use(int index, ICharacter &target)
{
	if (index < 0 || index >= INVENTORY_CAPACITY)
		return ;
	if (inventory[index])
	{
		std::cout << getName() << " uses slot [" << index << "]:\n";
		inventory[index]->use(target);
	}
}

std::string const &
Character::getName()
const
{
	return (name);
}