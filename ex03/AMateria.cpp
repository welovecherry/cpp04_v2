#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "🛠️ AMateria default Constructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) {
    this->type = type;
    std::cout << "🛠️ AMateria Constructor called." << std::endl;
}

AMateria::AMateria(AMateria const &src) {
    type = src.type;
    std::cout << "🛠️ AMateria copy Constructor called." << std::endl;
}

AMateria &AMateria::operator=(AMateria const &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    std::cout << "🛠️ AMateria assignment operator called." << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "🛠️ AMateria destructor called.\n" << std::endl;
}

std::string const &AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
