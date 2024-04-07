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

/* 제시된 AMateria 클래스 선언에서 use 메서드는 순수 가상 함수로 선언되지 않았습니다. 이는 use 메서드에 대한 구현을 제공해야 함을 의미합니다. 
그러나, AMateria는 추상 베이스 클래스로 보이며, clone 메서드가 순수 가상 함수로 선언되어 있어서 이 클래스의 인스턴스를 직접 생성할 수 없습니다. 따라서, use 메서드의 구현은 AMateria를 상속받는 구체 클래스에서 제공될 것으로 예상됩니다.

하지만, use 메서드에 대한 기본 구현을 제공하고자 한다면, 다음과 같이 AMateria.cpp 파일 내에서 해당 메서드를 구현할 수 있습니다. 이는 파생 클래스에서 오버라이드할 수 있는 기본 동작을 제공합니다:*/