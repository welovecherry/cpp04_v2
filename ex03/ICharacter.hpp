#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

/*  class AMateria; 부분은 **전방 선언(forward declaration)**이라고 합니다. 
이 기법은 한 클래스가 다른 클래스의 존재는 알려주지만, 
그 세부 사항은 나중에 알려준다는 의미를 가지고 있습니다. 
즉, 클래스의 이름만 선언하고, 클래스의 멤버 함수나 변수 등은 선언하지 않습니다.

- *1* 상호 참조 문제 해결**: 
`ICharacter`와 `AMateria` 같은 경우, 두 클래스가 서로를 참조해야 할 때가 있습니다.
    - 예를 들어, `ICharacter` 인터페이스 내에서 `AMateria` 타입의 객체를 사용해야 하고, 
    반대로 `AMateria` 클래스도 `ICharacter` 타입의 객체를 사용할 수 있습니다.
    - 이런 상황에서 두 파일이 서로를 `#include`하게 되면, 컴파일러는 무한 참조의 문제에 빠지게 됩니다. 
    이를 해결하기 위해 전방 선언을 사용합니다.

- *2*컴파일 속도 향상**: 
전방 선언을 사용하면 해당 클래스의 모든 세부 정보를 컴파일 시점에 알 필요가 없기 때문에, 
헤더 파일의 의존성이 줄어들고, 결과적으로 컴파일 속도가 향상됩니다.
*/

// AMateria 클래스를 전방 선언합니다. 
// 이는 ICharacter와 AMateria가 서로를 include하게 되는 상황을 방지하기 위함입니다.
class AMateria;

class ICharacter {
public:
    virtual ~ICharacter() {} // 가상 소멸자

    // 캐릭터의 이름을 반환하는 순수 가상 함수. 모든 캐릭터는 고유한 이름을 가짐
    virtual std::string const &getName() const = 0;

    // 특정 마법(Materia)을 장착하는 순수 가상 함수
    // 캐릭터는 여러 마법을 장착할 수 있으며 이를 활용할 수 있다.
    virtual void equip(AMateria* m) = 0;

    // 마법(Materia)을 장착 해제하는 순수 가상 함수
    virtual void unequip(int idx) = 0;

    // 특정 대상에게 마법(Materia)을 사용하는 순수 가상 함수
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif