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
        // 현재 객체의 모든 Materia 객체들을 삭제 후 NULL로 초기화
        for (int i = 0; i < 4; i++) {
            if (slots[i]) {
                delete slots[i];
                slots[i] = NULL;
            }
        }
        // rhs의 Materia 객체들을 깊은 복사
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