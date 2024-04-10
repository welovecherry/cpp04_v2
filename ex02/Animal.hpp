#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>


/* the default Animal class should not be instantiable. 
Fix the Animal class so nobody can instantiate it. */

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& src);
    Animal& operator=(const Animal& rhs);
    virtual ~Animal();


    /* virtual 키워드는 멤버 함수를 "가상 함수"로 만듭니다. 
    이는 해당 함수가 파생 클래스에서 오버라이드(재정의)될 수 있음을 의미합니다. 
    virtual로 선언된 함수는 실행 시간에 동적 바인딩을 사용하여 호출됩니다. 
    즉, 객체의 실제 타입에 따라 호출되는 함수의 버전이 결정됩니다.*/

    /** 추상 클래스** 는 최소 하나 이상의 순수 가상 함수를 포함하는 클래스로, 
    이 클래스 자체로는 객체를 만들 수 없습니다. 
    대신 이 클래스를 상속받는 자식 클래스에서 순수 가상 함수를 구현해야만, 그 자식 클래스의 객체를 생성할 수 있습니다.*/

    // virtual void makeSound() const;
    virtual void makeSound() const = 0;

    std::string getType() const;
};


#endif