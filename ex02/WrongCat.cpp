#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
    /* WrongAnimal 클래스로부터 상속받은 type 멤버 변수에 대한 접근이 가능하기 때문에, 
    WrongCat 클래스의 생성자 및 대입 연산자에서 
    this->type = type; 또는 this->type = rhs.type;와 같은 할당은 필요 없습니다. */
    // this->type = type;
    std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
    // 이 줄은 필요 없으며, WrongAnimal(src) 호출로 충분합니다.
    // this->type = src.type;
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    if (this != &rhs) {
        WrongAnimal::operator=(rhs);
    }
    std::cout << "WrongCat assignment operator called." << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called." << std::endl;
}
