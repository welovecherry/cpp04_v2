/* pdf 
-The Character possesses an inventory of 4 slots, 
which means 4 Materias at most. 

-The inventory is empty at construction.

-They equip the Materias in the first empty slot they find. 
This means, in this order: from slot 0 to slot 3.

-In case they try to add a Materia to a full inventory, 
or use/unequip an unexisting Materia,
don’t do anything (but still, bugs are forbidden).

-The unequip() member function must NOT delete the Materia! 
*/

/* Your Character must have a constructor taking its name as a parameter. 
Any copy (copy constructor or copy assignment operator) of a Character must be deep. 
During copy, the Materias of a Character must be deleted 
before the new ones are added to their inventory. 
Of course, the Materias must be deleted when a Character is destroyed.
*/

/* Character클래스(구현 클래스): ICharacter 인터페이스에 정의된 행동들을 실제로 구현하는 클래스입니다. */
#include "Character.hpp"
#include <iostream>

/* Your Character must have a constructor taking its name as a parameter.
The inventory is empty at construction */
Character::Character(std::string const &name) {
    this->name = name;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL; // 인벤토리 초기화
    }
}

/* - 만약 `src.inventory[i]`가 `NULL`이 아니라면 (즉, `Materia` 객체가 존재한다면), 
해당 `Materia` 객체의 `clone()` 메서드를 호출하여 새로운 `Materia` 객체를 생성하고, 
이를 현재 객체의 `inventory`에 할당합니다. 이는 `Materia`의 정확한 복제본을 만드는 과정입니다.

- 만약 `src.inventory[i]`가 `NULL`이라면 (즉, 해당 슬롯이 비어 있다면), 
현재 객체의 해당 `inventory` 슬롯도 `NULL`로 설정합니다.*/

/* Deep copy는 객체가 가진 모든 값과 함께, 객체가 참조하는 다른 객체들 또한 복사하여 새로운 메모리 위치에 할당하는 
복사 방식을 의미합니다. 
이 경우, Character 객체의 name 멤버와 inventory에 포함된 각 AMateria 객체들이 
새로운 메모리 위치에 복사됩니다. 
특히, AMateria 객체들은 clone() 메서드를 통해 각각 복제되므로, 
원본 Character 객체와 복사된 Character 객체가 서로 독립적인 AMateria 객체들을 가리키게 됩니다.*/

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


/* During copy, the Materias of a Character must be deleted 
before the new ones are added to their inventory. */

// 복사 할당 연산자: 다른 캐릭터 객체의 상태를 현재 객체에 할당
Character &Character::operator=(Character const &rhs) {
    if (this != &rhs) {
        name = rhs.name;
        for (int i = 0; i < 4; i++) {
            delete inventory[i]; // 기존 Materia 삭제
            if (rhs.inventory[i])
                inventory[i] = rhs.inventory[i]->clone(); // Materia 복제
                else
                inventory[i] = NULL;
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

// 캐릭터의 이름 반환
std::string const &Character::getName() const {
    return name;
}

// Materia 장착: 첫 번째 빈 슬롯에 Materia 추가
void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) { // 빈 슬롯이라면 Materia 추가
            inventory[i] = m;
            break;
        }
    }
}

// Materia 장착 해제: 지정된 인덱스의 Materia 제거하지만 삭제하지는 않음
void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) // 유효한 인덱스라면 Materia 제거
        inventory[idx] = NULL;
}

// use(): 지정된 인덱스의 Materia를 사용하여 대상에게 효과 적용
void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) { //유효한 인덱스와 Materia 존재 확인
        inventory[idx]->use(target); // Materia 사용
    }
}