#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& src);
    Animal& operator=(const Animal& rhs);

    /*기본 클래스의 소멸자가 virtual로 선언되어 있지 않으면, 
    파생 클래스의 객체를 기본 클래스의 포인터를 통해 삭제할 때
    파생 클래스의 소멸자가 호출되지 않아 리소스 누수와 같은 문제가 발생할 수 있음.*/
    virtual ~Animal();


    /* virtual 키워드는 멤버 함수를 "가상 함수"로 만듭니다. 
    이는 해당 함수가 파생 클래스에서 오버라이드(재정의)될 수 있음을 의미합니다. 
    virtual로 선언된 함수는 실행 시간에 동적 바인딩을 사용하여 호출됩니다. 
    즉, 객체의 실제 타입에 따라 호출되는 함수의 버전이 결정됩니다.*/

    // virtual void makeSound() const; ex01버전
    
    // 이번 문제에서 요구한것으로 수정
    virtual void makeSound() const = 0;

    std::string getType() const;
};


#endif