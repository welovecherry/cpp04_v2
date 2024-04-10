#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

/* pdf 
The Character possesses an inventory of 4 slots, which means 4 Materias at most. 
The inventory is empty at construction. 

They equip the Materias in the first empty slot they find. 
This means, in this order: from slot 0 to slot 3. 

In case they try to add a Materia to a full inventory, 
or use/unequip an unexisting Materia,
don’t do anything (but still, bugs are forbidden). 
The unequip() member function must NOT delete the Materia!

1. ### 인덱스 범위 밖의 Materia
- `Character`의 `inventory`에는 최대 4개의 `Materia` 객체가 저장될 수 있습니다.
- 즉, 유효한 인덱스 범위는 0부터 3까지입니다. 만약 프로그램에서 `equip`, `unequip`, 또는 `use` 함수를 호출할 때 
유효 범위를 벗어나는 인덱스(예: -1, 4, 5 등)를 사용한다면, 그 인덱스에 해당하는 `Materia`는 "존재하지 않는다".

2. ### 할당되지 않은 슬롯의 Materia
- `Character` 객체가 생성될 때, 모든 `inventory` 슬롯은 초기에 ``로 설정됩니다.
- 즉, 아직 어떤 `Materia` 객체도 할당되지 않은 상태입니다.
- 만약 이 상태에서 `unequip` 또는 `use` 함수가 특정 인덱스의 `Materia`에 대해 호출된다면, 
해당 인덱스에는 "존재하지 않는 Materia"가 있는 것으로 간주됩니다. 
왜냐하면 그 위치에 아직 어떠한 `Materia` 객체도 할당되지 않았기 때문입니다.
*/

/* Your Character must have a constructor taking its name as a parameter. 
Any copy (using copy constructor or copy assignment operator) of a Character must be deep. 
During deep copy, the Materias of a Character must be deleted 
before the new ones are added to their inventory. 
Of course, the Materias must be deleted when a Character is destroyed.
*/

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4]; // 마법재료(Materia)를 저장할 수 있는 인벤토리

public:
    Character(std::string const &name);
    Character(Character const &src);
    Character &operator=(Character const &rhs);
    virtual ~Character();

    virtual std::string const &getName() const;

    // 특정 마법(Materia)을 장착합니다.
    virtual void equip(AMateria* m);

    // 마법(Materia)을 장착 해제합니다.
    virtual void unequip(int idx);

    // 특정 대상에게 마법(Materia)을 사용합니다.
    virtual void use(int idx, ICharacter& target);
};
#endif