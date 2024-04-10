#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
/* 문제 설명에서는 use() 함수가 ICharacter 타입의 인자를 받아서 사용하도록 되어 있습니다 */

class Ice : public AMateria {
public:
    Ice();
    Ice(Ice const &src);
    Ice &operator=(Ice const &rhs);
    virtual ~Ice();

    virtual Ice* clone() const; // 자신의 인스턴스를 클론(복사)하는 함수
    virtual void use(ICharacter& target); // 특정 캐릭터를 대상으로 마법을 사용하는 함수
};

#endif

/*
C++에서 `virtual` 키워드를 사용하는 것이 선택 사항인 이유는, 
기본 클래스에서 멤버 함수를 `virtual`로 선언한 경우, 
그 함수를 파생 클래스에서 오버라이드(재정의)할 때 `virtual` 키워드를 명시적으로 사용하지 않아도 
해당 함수는 자동으로 가상 함수로 간주되기 때문입니다. 
즉, 파생 클래스에서 오버라이드하는 멤버 함수 앞에 `virtual` 키워드를 다시 쓰는 것은 선택적이며, 
이는 주로 코드의 가독성과 의도를 명확히 하기 위한 목적으로 사용됩니다.

C++ 표준에서는 기본 클래스의 가상 함수를 파생 클래스에서 오버라이드할 때 `virtual` 키워드를 생략할 수 있도록 허용합니다. 
하지만, 이 함수가 여전히 가상 함수임을 명시하기 위해 `virtual` 키워드를 사용하는 것이 좋습니다. 이
러한 관행은 코드를 읽는 다른 개발자들에게 해당 함수가 기본 클래스에서 정의된 가상 함수를 오버라이드하고 있음을 명확히 알려주며, 클래스의 다형성에 대한 이해를 돕습니다.
결론적으로, C++98 및 그 이전 버전에서는 `virtual` 키워드를 사용하는 것이 선택적이지만, 코드의 명확성과 의도를 전달하기 위해 사용하는 것이 좋음.
*/