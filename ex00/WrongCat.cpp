#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
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
