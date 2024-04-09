/* 중요한 점은, makeSound 메서드는 가상 함수로 선언되지 않았습니다. 
이는 WrongAnimal 클래스와 그 파생 클래스들 사이에서 다형성을 적용할 의도가 없음을 나타냅니다. 
즉, 파생 클래스에서 makeSound 함수를 오버라이딩해도, WrongAnimal 타입의 포인터나 참조를 통해 호출될 때 
기본 클래스의 makeSound 함수가 호출됩니다. 
이러한 특성은 잘못된 동물의 소리가 출력되는 예시를 보여주기 위한 것입니다.*/

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
    this->type = src.type;
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    std::cout << "WrongAnimal assignment operator called." << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called." << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}