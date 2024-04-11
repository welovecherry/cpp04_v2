#include "Character.hpp"
#include <iostream>

/* Your Character must have a constructor taking its name as a parameter.
The inventory is empty at construction */
Character::Character(std::string const &name) {
    this->name = name;
    addr_idx = 0;
    for (int i = 0; i < MAX_SLOT; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(Character const &src) {
    this->name = src.name;
    for (int i = 0; i < MAX_SLOT; i++) {
        delete inventory[i];
        inventory[i] = NULL;
    }
    for (int i = 0; i < MAX_SLOT; i++) {
        if (src.inventory[i])
            inventory[i] = src.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

/* During copy, the Materias of a Character must be deleted 
before the new ones are added to their inventory. */
Character& Character::operator=(Character const &rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        for (int i = 0; i < MAX_SLOT; i++) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
        for (int i = 0; i < MAX_SLOT; i++) {
            if (rhs.inventory[i])
                this->inventory[i] = rhs.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < MAX_SLOT; i++) {
        delete inventory[i]; 
    }
    
    for(int i = 0; i < addr_idx; i++) {
        delete addr_tmp[i];
    }
}

std::string const &Character::getName() const {
    return name;
}

void Character::equip(AMateria* m)
{
    if (m == NULL) {
        std::cout << "Warning: Materia slot is empty" << std::endl;
        return;
    }

    for (int i = 0; i < MAX_SLOT; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            std::cout << "✅ Materia equipped!" << std::endl;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= MAX_SLOT) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (this->inventory[idx] != NULL) {
        addr_tmp[addr_idx] = this->inventory[idx];
        addr_idx++;
        this->inventory[idx] = NULL;
        std::cout << "❎ Materia unequipped from slot " << idx << "." << std::endl;
    } else {
        std::cout << "No Materia found in the selected slot." << std::endl;
    }
}

/* 
The use(int, ICharacter&) member function will have to use the Materia at the slot[idx], 
and pass the target parameter to the AMateria::use function.*/
void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= MAX_SLOT) {
        std::cout << "Invalid index. Materia cannot be used." << std::endl;
        return;
    }

    if (this->inventory[idx]) {
        this->inventory[idx]->use(target);
    } else {
        std::cout << "No Materia found" << std::endl;
    }
}
