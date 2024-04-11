#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "🐶Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "🐶Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
    }
    std::cout << "🐶Dog assignment operator called." << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "🐶Dog destructor called." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "🐶Dog: Bow Wow" << std::endl;
}