#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        slots[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& src) {
    *this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; i++) {
            if (slots[i]) {
                delete slots[i];
                slots[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (rhs.slots[i] != NULL) 
                slots[i] = rhs.slots[i]->clone();
        }
    }
    return *this;
}


MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete slots[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (slots[i] == NULL) {
            slots[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (slots[i]->getType() == type) {
            return slots[i]->clone();
        }
    }
    return NULL;
}