#include "Cat.hpp"
#include <iostream>

/* 파생 클래스의 생성자에서 기본 클래스의 생성자를 명시적으로 호출하는 것은 좋은 방법입니다.
 Cat 객체가 생성될 때, Animal 클래스의 생성자를 호출하여 type을 "Cat"으로 설정하고, 
 추가적으로 Cat 생성자에서 커스텀 로직(여기서는 생성자 호출 메시지를 출력)을 실행합니다. 
 이 방식은 파생 클래스가 자신의 특성을 명확하게 반영하면서도, 
 기본 클래스의 구성 요소를 적절히 활용하고 초기화하는 방법을 제공합니다.*/
 
 // 방법 1: 멤버 이니셜라이저 리스트 활용
Cat::Cat() : Animal(), brain(new Brain()) {
    // TODO: "cat"으로 초기화 해야할까??
    std::cout << "Cat constructor called." << std::endl;
}

// 방법 2: 본문에서 동적 할당
// Cat::Cat() : Animal("Cat") {
//     brain = new Brain();
//     std::cout << "Cat constructor called." << std::endl;
// }

/* Cat 클래스의 복사 생성자는 Animal 클래스로부터 상속받은 멤버 변수를 올바르게 처리하기 위해 
기본 클래스의 복사 생성자를 호출함 */
// 방법 1: 멤버 이니셜라이저 리스트 활용

Cat::Cat(const Cat& src) : Animal(src), brain(new Brain(*src.brain)) {
    std::cout << "Cat copy constructor called." << std::endl;
}

// 방법 2: 본문에서 동적 할당
// Cat::Cat(const Cat& src) : Animal(src) {
//     brain = new Brain(*src.brain);
//     std::cout << "Cat copy constructor called." << std::endl;
// }

Cat& Cat::operator=(const Cat& rhs) {
/* 기본 클래스인 Animal의 대입 연산자를 호출하여, 
Animal 부분의 상태를 rhs에서 현재 객체로 복사합니다.*/

/* 기존 브레인 객체 해제하고 새로 할당하는 과정이 필요한 이유는 깊은 복사(deep copy)를 구현하기 위해서입니다. 
Dog 객체가 다른 Dog 객체에 의해 대입되는 경우, 단순히 포인터 값을 복사하는 것이 아니라, 
Brain 객체의 실제 내용을 복사하여 새로운 Brain 객체를 할당함으로써
두 Dog 객체가 서로 독립적인 Brain 객체를 가지게 하기 위함입니다.*/
    if (this != &rhs) {
        Animal::operator=(rhs);
        delete brain;
        brain = new Brain(*rhs.brain);
        std::cout << "Cat assignment operator called." << std::endl;
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called." << std::endl;
}

// makeSound 함수 오버라이딩
void Cat::makeSound() const {
    std::cout << "Cat: Meow Meow" << std::endl;
}