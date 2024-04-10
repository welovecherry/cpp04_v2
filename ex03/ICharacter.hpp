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
    virtual ~ICharacter() {}

    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
#endif

/* 모두 virtual을 사용한 이유 
`virtual` 키워드를 사용하는 주된 이유는 C++에서 다형성을 지원하기 위해서입니다. 
특히, `Character` 클래스가 `ICharacter` 인터페이스를 구현할 때, 
이 인터페이스 내의 모든 함수는 순수 가상 함수로 정의되어 있으며, 
`Character` 클래스는 이러한 인터페이스의 모든 함수를 구현해야 합니다. 
여기서의 `virtual` 키워드 사용은 다음과 같은 중요한 목적이 있습니다:

1. **다형성 지원**: `virtual`을 사용함으로써, 파생 클래스에서 해당 함수를 오버라이드(재정의)할 수 있게 됩니다. 
이를 통해, 파생 클래스의 객체를 기반 클래스의 포인터나 참조를 통해 다룰 때, 실행 시간에 결정되는 동적 바인딩을 통해 
파생 클래스에 구현된 함수가 호출됩니다. 이것이 다형성의 핵심입니다.

2. **인터페이스 구현**: `Character` 클래스는 `ICharacter` 인터페이스를 구현합니다. 
인터페이스에 선언된 함수들은 기본적으로 다형적 행위를 위해 설계되었으므로, 이를 구현하는 클래스에서도 
`virtual` 키워드를 사용하여 해당 함수들이 다형성을 가지도록 합니다.

따라서, 이러한 함수들에 virtual 키워드를 사용하는 것은, 해당 클래스가 다른 클래스에 의해 
상속될 것을 고려하여 설계되었음을 나타냅니다. 
이는 파생 클래스에서의 오버라이딩을 통해 다양한 행위를 구현할 수 있는 유연성을 제공합니다.
 */



