#include "Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice") {
    std::cout << "🧊 Ice constructor called." << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src) {
    std::cout << "🧊 Ice copy constructor called." << std::endl;
}

Ice &Ice::operator=(Ice const &rhs) {
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    std::cout << "🧊 Ice assignment operator called." << std::endl;
    return *this;
}

Ice::~Ice() {
    std::cout << "🧊 Ice Destructor called." << std::endl;
}

Ice* Ice::clone() const {
    return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
