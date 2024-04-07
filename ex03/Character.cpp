#include "Character.hpp"
#include <iostream>

/* Your Character must have a constructor taking its name as a parameter.
The inventory is empty at construction */
Character::Character(std::string const &name) {
    this->name = name;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

/* - 만약 `src.inventory[i]`가 `NULL`이 아니라면 (즉, `Materia` 객체가 존재한다면), 
해당 `Materia` 객체의 `clone()` 메서드를 호출하여 새로운 `Materia` 객체를 생성하고, 
이를 현재 객체의 `inventory`에 할당합니다. 이는 `Materia`의 정확한 복제본을 만드는 과정입니다.

- 만약 `src.inventory[i]`가 `NULL`이라면 (즉, 해당 슬롯이 비어 있다면), 
현재 객체의 해당 `inventory` 슬롯도 `NULL`로 설정합니다.*/

/* Deep copy는 객체가 가진 모든 값과 함께, 객체가 참조하는 다른 객체들 또한 복사하여 
새로운 메모리 위치에 할당하는 복사 방식을 의미합니다. 
이 경우, Character 객체의 name 멤버와 inventory에 포함된 각 AMateria 객체들이 
새로운 메모리 위치에 복사됩니다. 
특히, AMateria 객체들은 clone() 메서드를 통해 각각 복제되므로, 
원본 Character 객체와 복사된 Character 객체가 서로 독립적인 AMateria 객체들을 가리키게 됩니다.*/

/* "During copy, the Materias of a Character must be deleted 
before the new ones are added to their inventory."를 고려할 때, 
복사 작업 중에 기존의 Materia 객체들을 삭제하고 새로운 것들을 인벤토리에 추가해야 한다는 것이 맞습니다. 
하지만, 이 과정은 복사 생성자보다는 (복사 할당 연산자)에서 더 중요한 의미를 갖습니다. 
왜냐하면 복사 생성자는 객체가 새로 생성될 때 호출되므로, 대상 객체의 인벤토리가 비어 있을 것이기 때문입니다. */

// 복사 생성자: 다른 캐릭터 객체로부터 깊은 복사를 수행
Character::Character(Character const &src) {
    this->name = src.name;
    for (int i = 0; i < 4; i++) {
        if (src.inventory[i])
            inventory[i] = src.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

// 복사 할당 연산자: 다른 캐릭터 객체의 상태를 현재 객체에 할당
/* During copy, the Materias of a Character must be deleted 
before the new ones are added to their inventory. */
Character& Character::operator=(Character const &rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        // 기존 Materia 객체들 삭제
        for (int i = 0; i < 4; i++) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
        // 새로운 Materia 객체들 복사
        for (int i = 0; i < 4; i++) {
            if (rhs.inventory[i])
                this->inventory[i] = rhs.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

// 소멸자: 할당된 모든 Materia 삭제
Character::~Character() {
    for (int i = 0; i < 4; i++) {
        delete inventory[i]; 
    }
}

// 아래 가상함수 
// 캐릭터의 이름 반환
std::string const &Character::getName() const {
    return name;
}

// Materia 장착: 첫 번째 빈 슬롯에 Materia 추가
void Character::equip(AMateria* m)
{
	if (m == NULL) {
		std::cout << "Warning: Materia slot is empty" << std::endl;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!this->inventory[i]) { // 빈 슬롯이라면 Materia 추가
			this->inventory[i] = m;
			std::cout << "Materia equipped!" << std::endl;
			return;
		}
	}

	std::cout << "Inventory is full." << std::endl;
}
// void Character::equip(AMateria *m) {
//     for (int i = 0; i < 4; i++) {
//         if (!inventory[i]) { // 빈 슬롯이라면 Materia 추가
//             inventory[i] = m;
//             break;
//         }
//     }
// }

/* 목적: 캐릭터의 inventory 배열에서 지정된 인덱스의 Materia를 NULL로 설정하여 장착 해제. 
단, 이 함수는 Materia 객체를 메모리에서 삭제하지 않으며, 단순히 인벤토리에서의 참조를 제거합니다.*/
// Materia 장착 해제: 지정된 인덱스의 Materia 제거하지만 삭제하지는 않음
// void Character::unequip(int idx) {
//     if (idx >= 0 && idx < 4) // 유효한 인덱스라면 Materia 제거
//         inventory[idx] = NULL;
// }
void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    if (!this->inventory[idx]) { // 해당 슬롯에 Materia가 없으면
        std::cout << "No Materia found in the selected slot." << std::endl;
        return;
    }

    // Materia를 장착 해제하고 슬롯을 비움
    this->inventory[idx] = NULL;
    std::cout << "Materia unequipped from slot " << idx << "." << std::endl;
}


/* 
The use(int, ICharacter&) member function will have to use the Materia at the slot[idx], 
and pass the target parameter to the AMateria::use function.*/
// use(): 지정된 인덱스의 Materia를 사용하여 대상에게 Materia의 기능을 활성화 함
void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid index. Materia cannot be used." << std::endl;
        return;
    }

    if (this->inventory[idx]) { // 해당 슬롯에 Materia가 존재한다면
        this->inventory[idx]->use(target);
    } else {
        std::cout << "No Materia found" << std::endl;
    }
}
// void Character::use(int idx, ICharacter& target) {
//     if (idx >= 0 && idx < 4 && inventory[idx]) { //유효한 인덱스와 Materia 존재 확인
//         inventory[idx]->use(target); // Materia 사용
//     }
// }
