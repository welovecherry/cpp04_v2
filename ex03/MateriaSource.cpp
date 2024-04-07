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

// MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
//     if (this != &rhs) {
//         for (int i = 0; i < 4; ++i) {
//             delete slots[i];
//             if (rhs.slots[i]) slots[i] = rhs.slots[i]->clone();
//             else slots[i] = NULL;
//         }
//     }
//     return *this;
// }
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    if (this != &rhs) {
        // 1단계: 현재 객체의 모든 Materia 객체들을 삭제
        for (int i = 0; i < 4; i++) {
            if (slots[i]) {
                delete slots[i];
                slots[i] = NULL; // 삭제 후 NULL로 초기화
            }
        }

        // 2단계: rhs의 Materia 객체들을 깊은 복사
        for (int i = 0; i < 4; i++) {
            if (rhs.slots[i]) slots[i] = rhs.slots[i]->clone();
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
/* createMateria(std::string const &)
Returns a new Materia. 
The latter is a copy of the Materia previously learned by the MateriaSource 
whose type equals the one passed as parameter. 
Returns 0 if the type is unknown.*/
AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (slots[i] && (slots[i]->getType() == type)) {
            return slots[i]->clone();
        }
    }
    return NULL;
}