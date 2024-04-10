#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain()) {
    std::cout << "😺Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src), brain(new Brain(*src.brain)) {
    std::cout << "😺Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        delete brain;
        brain = new Brain(*rhs.brain);
        std::cout << "😺Cat assignment operator called." << std::endl;
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "😺Cat destructor called." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "😺Cat: Meow Meow" << std::endl;
}