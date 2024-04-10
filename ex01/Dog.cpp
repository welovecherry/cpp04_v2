#include "Dog.hpp"
#include <iostream>

/* 문제의 의도파악
: brain 멤버는 new Brain()을 사용해 동적으로 할당됩니다. 
이는 Dog 객체마다 독립적인 Brain 객체를 갖게 합니다.*/

// 멤버 이니셜라이저 리스트 사용
Dog::Dog() : Animal(), brain(new Brain()) {
    std::cout << "🐶Dog constructor called." << std::endl;
}


/*  정확히 말하면, 복사 생성자도 하나의 생성자이며, 객체의 생성 과정에 관여합니다. 
"Upon construction, Dog and Cat will create their Brain using new Brain();"
라는 문제의 지시사항은 모든 생성 과정, 즉 객체가 새로 생성될 때마다 적용되는데, 
이는 복사 생성자에도 해당됩니다.*/

/* 복사 생성자에서 `brain = new Brain(*src.brain);`
 구문을 사용하는 이유는 원본 객체의 `Brain` 객체를 깊은 복사하기 위해서입니다. 
 여기서 `src`는 복사하고자 하는 원본 `Dog` 객체를 가리키며, 
 `src.brain`은 원본 `Dog` 객체의 `Brain` 객체에 대한 포인터입니다. 
 `*src.brain`은 이 포인터가 가리키는 `Brain` 객체 자체, 즉 원본 `Brain` 객체에 대한 참조를 의미함.

- `src.brain`은 원본 `Dog` 객체의 `Brain` 포인터입니다.
- *`src.brain`은 포인터를 역참조하여, 그 포인터가 가리키는 `Brain` 객체를 얻습니다. 
즉, 원본 `Brain` 객체에 접근합니다.*/

// 방법1: 멤버 이니셜라이저 리스트 사용
//Dog::Dog(const Dog& src) : Animal(src), brain(new Brain(*src.brain)) {
//    std::cout << "🐶Dog copy constructor called." << std::endl;
//}
Dog::Dog(const Dog& src) : Animal(src), brain(new Brain(*src.brain)) {
    std::cout << "🐶Dog copy constructor called." << std::endl;
}


// 방법2: 본문에서 동적할당
// Dog::Dog(const Dog& src) : Animal(src) {
//     brain = new Brain(*src.brain);
//     std::cout << "Dog copy constructor called." << std::endl;
// }

Dog& Dog::operator=(const Dog& rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);

/* 기존 브레인 객체 해제하고 새로 할당하는 과정이 필요한 이유는 깊은 복사(deep copy)를 구현하기 위해서입니다. 
Dog 객체가 다른 Dog 객체에 의해 대입되는 경우, 단순히 포인터 값을 복사하는 것이 아니라, 
Brain 객체의 실제 내용을 복사하여 새로운 Brain 객체를 할당함으로써
두 Dog 객체가 서로 독립적인 Brain 객체를 가지게 하기 위함입니다.*/
        delete brain; // 기존 브레인 객체 해제
        brain = new Brain(*rhs.brain); // 새 브레인 객체 할당
    }
    std::cout << "🐶Dog assignment operator called." << std::endl;
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "🐶Dog destructor called." << std::endl;
}

// makeSound 함수 오버라이딩
void Dog::makeSound() const {
    std::cout << "🐶Dog: Bow Wow" << std::endl;
}
