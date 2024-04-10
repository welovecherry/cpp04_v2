#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
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