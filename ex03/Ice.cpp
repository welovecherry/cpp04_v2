#include "Ice.hpp"
#include <iostream>

Ice::Ice() {
    this->type = "ice";
    std::cout << "Ice default Constructor called." << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src) {
    std::cout << "Ice copy Constructor called." << std::endl;
}

Ice &Ice::operator=(Ice const &rhs) {
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    std::cout << "Ice assignment operator called." << std::endl;
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice Destructor called." << std::endl;
}


// 함수 구현
Ice* Ice::clone() const {
    return new Ice(*this); // Ice 객체의 복사본을 생성하여 반환
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    // 특정 캐릭터를 대상으로 마법을 사용하는 함수 구현
}
