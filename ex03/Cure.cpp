#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "💊 Cure default Constructor called." << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src) {
    std::cout << "💊 Cure copy Constructor called." << std::endl;
}

Cure &Cure::operator=(Cure const &rhs) {
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    std::cout << "💊 Cure assignment operator called." << std::endl;
    return *this;
}

Cure::~Cure() {
    std::cout << "💊 Cure Destructor called." << std::endl;
}

Cure* Cure::clone() const {
    return new Cure(*this);  // Cure 객체의 복사본을 생성하여 반환
}

// concrete class member function
void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}