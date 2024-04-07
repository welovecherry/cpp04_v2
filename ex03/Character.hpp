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
    AMateria* inventory[4]; // 마법(Materia)을 저장할 수 있는 인벤토리

public:
    Character(std::string const &name);
    Character(Character const &src);
    Character &operator=(Character const &rhs);
    virtual ~Character();

/* 모두 virtual을 사용한 이유 
`virtual` 키워드를 사용하는 주된 이유는 C++에서 다형성을 지원하기 위해서입니다. 
특히, `Character` 클래스가 `ICharacter` 인터페이스를 구현할 때, 
이 인터페이스 내의 모든 함수는 순수 가상 함수로 정의되어 있으며, 
`Character` 클래스는 이러한 인터페이스의 모든 함수를 구현해야 합니다. 
여기서의 `virtual` 키워드 사용은 다음과 같은 중요한 목적이 있습니다:

1. **다형성 지원**: `
virtual`을 사용함으로써, 파생 클래스에서 해당 함수를 오버라이드(재정의)할 수 있게 됩니다. 
이를 통해, 파생 클래스의 객체를 기반 클래스의 포인터나 참조를 통해 다룰 때, 
실행 시간에 결정되는 동적 바인딩을 통해 
파생 클래스에 구현된 함수가 호출됩니다. 이것이 다형성의 핵심입니다.

2. **인터페이스 구현**: `Character` 클래스는 `ICharacter` 인터페이스를 구현합니다. 
인터페이스에 선언된 함수들은 기본적으로 다형적 행위를 위해 설계되었으므로, 이를 구현하는 클래스에서도 
`virtual` 키워드를 사용하여 해당 함수들이 다형성을 가지도록 합니다.

따라서, 이러한 함수들에 virtual 키워드를 사용하는 것은, 해당 클래스가 다른 클래스에 의해 
상속될 것을 고려하여 설계되었음을 나타냅니다. 
이는 파생 클래스에서의 오버라이딩을 통해 다양한 행위를 구현할 수 있는 유연성을 제공합니다.
 */

    // ICharacter 인터페이스 구현
    virtual std::string const &getName() const;

    // 특정 마법(Materia)을 장착합니다.
    virtual void equip(AMateria* m);

    // 마법(Materia)을 장착 해제합니다.
    virtual void unequip(int idx);

    // 특정 대상에게 마법(Materia)을 사용합니다.
    virtual void use(int idx, ICharacter& target);
};
#endif