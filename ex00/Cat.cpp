#include "Cat.hpp"
#include <iostream>

/* 파생 클래스의 생성자에서 기본 클래스의 생성자를 명시적으로 호출하는 것은 좋은 방법입니다.
 Cat 객체가 생성될 때, Animal 클래스의 생성자를 호출하여 type을 "Cat"으로 설정하고, 
 추가적으로 Cat 생성자에서 커스텀 로직(여기서는 생성자 호출 메시지를 출력)을 실행합니다. 
 이 방식은 파생 클래스가 자신의 특성을 명확하게 반영하면서도, 
 기본 클래스의 구성 요소를 적절히 활용하고 초기화하는 방법을 제공합니다.*/
Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << "Cat constructor called." << std::endl;
}

/* Cat 클래스의 복사 생성자는 Animal 클래스로부터 상속받은 멤버 변수를 올바르게 처리하기 위해 
기본 클래스의 복사 생성자를 호출함 */
Cat::Cat(const Cat& src) : Animal(src) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    /* 기본 클래스인 Animal의 대입 연산자를 호출하여, 
    Animal 부분의 상태를 rhs에서 현재 객체로 복사합니다.*/
    if (this != &rhs) {
        Animal::operator=(rhs);
        std::cout << "Cat assignment operator called." << std::endl;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat: Meow Meow" << std::endl;
}