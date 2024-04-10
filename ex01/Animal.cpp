#include "Animal.hpp"

Animal::Animal() {
    this->type = "Animal";
    std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& src) {
    this->type = src.type;
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    std::cout << "Animal assignment operator called." << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}

// makeSound 멤버 함수 구현 (가상 함수)

/* C++에서는 virtual 키워드를 클래스의 멤버 함수 선언에만 사용하며, 
소스 파일(.cpp)에서 해당 함수의 정의 부분에 virtual 키워드를 사용하지 않아도 괜찮습니다.*/
/* virtual 키워드는 함수가 가상 함수임을 나타내며, 
이는 해당 함수가 파생 클래스에서 오버라이드될 수 있음을 의미합니다. */
void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}