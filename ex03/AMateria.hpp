#ifndef AMATERIA_H
#define AMATERIA_H

#include "ICharacter.hpp"
#include <iostream>
#include <string>

/* 용도: AMateria 클래스는 마법 재료의 기본적인 인터페이스를 제공합니다. 
예를 들어, 공격 마법, 방어 마법, 회복 마법 등을 AMateria를 상속받아 구현할 수 있습니다.

사용법: AMateria를 상속받는 구체 클래스(예: Ice, Cure)를 정의하고, 
순수 가상 함수인 clone()과 use()를 구현합니다.

-clone 함수는 해당 마법 재료의 복제본을 생성하여 반환하고, 
-use 함수는 마법 재료가 사용될 때의 효과(예: 대상에게 피해를 주거나 치유를 함)를 구현합니다.
*/

class AMateria {
protected:
    std::string type;

public:
    AMateria();
    AMateria(std::string const& type);
    AMateria(AMateria const &src);
    AMateria &operator=(AMateria const &rhs);
    virtual ~AMateria();

    std::string const &getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target); 
};

#endif