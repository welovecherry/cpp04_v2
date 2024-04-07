#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "AMateria default Constructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) {
    this->type = type;
    std::cout << "AMateria Constructor called." << std::endl;
}

AMateria::AMateria(AMateria const &src) {
    type = src.type;
    std::cout << "AMateria copy Constructor called." << std::endl;
}

AMateria &AMateria::operator=(AMateria const &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    std::cout << "AMateria assignment operator called." << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called." << std::endl;
}

std::string const &AMateria::getType() const {
    return this->type;
}

/* AMateria 클래스의 clone과 use 함수가 순수 가상 함수로 선언되었기 때문에, 
이들을 소스 파일에서 구현하지 않았습니다. 

순수 가상 함수는 C++에서 클래스를 추상 클래스로 만드는 방법 중 하나입니다. 
추상 클래스는 인스턴스화될 수 없으며, 주로 상속을 위한 기본 클래스로 사용됩니다.
*/