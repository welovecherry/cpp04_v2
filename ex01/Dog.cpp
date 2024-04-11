#include "Dog.hpp"
#include <iostream>

// A copy of a Dog or a Cat mustn’t be shallow.

Dog::Dog() : Animal(), brain(new Brain()) {
    std::cout << "🐶Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src), brain(new Brain(*src.brain)) {
    std::cout << "🐶Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    std::cout << "🐶Dog assignment operator called." << std::endl;
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "🐶Dog destructor called." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "🐶Dog: Bow Wow" << std::endl;
}
