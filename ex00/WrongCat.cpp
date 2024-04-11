#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
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

void WrongCat::makeSound() const
{
	std::cout << "🐱WrongCat: wrong Meow Meow" << std::endl;
}
