// delete it laterrrrrrrr


// #include <iostream>



// int main() {
//     std::cout << "\n---- begin of main statement ---- \n" << std::endl;
    
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();

//     std::cout << "j의 소리: ";
//     j->makeSound();

//     std::cout << "meta의 소리: ";
//     meta->makeSound();

//     std::cout << "\n----- End of main statement ----- \n" << std::endl;

//     delete i; // 동적 할당된 메모리 해제
//     delete j;
//     delete meta;
    
//     return 0;
// }


// #ifndef ANIMAL_H
// #define ANIMAL_H

// #include <iostream>
// #include <string>

// // Animal 클래스 정의
// class Animal {
// protected:
//     std::string type; // 동물의 종류를 저장하는 변수

// public:
//     Animal(); // 기본 생성자
//     Animal(const Animal& other); // 복사 생성자
//     Animal& operator=(const Animal& other); // 대입 연산자 오버로딩
//     virtual ~Animal(); // 소멸자

//     virtual void makeSound() const; // 동물의 소리를 내는 함수
//     std::string getType() const; // 동물의 종류를 반환하는 함수
// };

// #endif // ANIMAL_H


// #include "Animal.h"

// // 매개변수를 가진 생성자 구현
// Animal::Animal(std::string type) : type(type) {
//     std::cout << "Animal of type " << type << " created" << std::endl;
// }

// // 복사 생성자 구현
// Animal::Animal(const Animal& src) : type(src.type) {
//     std::cout << "Animal of type " << type << " copied" << std::endl;
// }

// // 대입 연산자 오버로딩 구현
// Animal& Animal::operator=(const Animal& rhs) {
//     if (this != &rhs) { // 자기 자신에 대한 대입을 방지
//         this->type = rhs.type;
//     }
//     std::cout << "Animal of type " << type << " assigned" << std::endl;
//     return *this;
// }

// // 소멸자 구현
// Animal::~Animal() {
//     std::cout << "Animal of type " << type << " destroyed" << std::endl;
// }

// // makeSound 멤버 함수 구현 (가상 함수)
// void Animal::makeSound() const {
//     std::cout << "Some animal sound" << std::endl;
// }

// // getType 멤버 함수 구현
// std::string Animal::getType() const {
//     return type;
// }

// #ifndef CAT_HPP
// #define CAT_HPP

// #include "Animal.hpp"

// class Cat : public Animal {
// public:
//     Cat(); // 기본 생성자는 "Cat"으로 type을 초기화
//     Cat(const Cat& src); // 복사 생성자
//     Cat& operator=(const Cat& rhs); // 대입 연산자 오버로딩
//     virtual ~Cat(); // 소멸자

//     virtual void makeSound() const; // 고양이의 소리를 출력
// };

// #endif // CAT_HPP

// #include "Cat.hpp"

// // 기본 생성자에서 "Cat"으로 type을 초기화
// Cat::Cat() : Animal("Cat") {
//     std::cout << "A cat is created." << std::endl;
// }

// Cat::Cat(const Cat& src) : Animal(src) {
//     std::cout << "A cat is copied." << std::endl;
// }

// Cat& Cat::operator=(const Cat& rhs) {
//     Animal::operator=(rhs); // 기본 클래스의 대입 연산자 사용
//     return *this;
// }

// Cat::~Cat() {
//     std::cout << "A cat is destroyed." << std::endl;
// }

// void Cat::makeSound() const {
//     std::cout << "Meow" << std::endl;
// }


// ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    
//     // : ClapTrap(name)으로 이미 초기화했으므로 네임을 주석처리함.
//     // _name = name;
//     _hitPoints = 100;
//     _energyPoints = 50;
//     _attackDamage = 20;
//     std::cout << "ScavTrap constructor called initializing "  << _hitPoints << " hit points, " \
//     << _energyPoints << " energy points, and " << _attackDamage << " attack damage.\n" \
//     << std::endl;
// }

// // 복사 생성자
// ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
//     _name = src._name;
//     _hitPoints = src._hitPoints;
//     _energyPoints = src._energyPoints;
//     _attackDamage = src._attackDamage;
//     std::cout << "ScavTrap copy constructor called."<< std::endl;
// }


// // 대입 연산자
// ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
//     if (this != &rhs) {
//         // 기반 클래스 속성 복사 
//         // 이 한 줄로 ClapTrap에 있는 모든 속성들이 현재 FragTrap 객체에 올바르게 설정됨
//         /*간단히 말해, ()는 함수 호출을 나타내는 문법으로, 
//         여기서는 operator= 함수를 호출하는 데 사용되므로 반드시 필요합니다.*/
//         ClapTrap::operator=(rhs);
//         _name = rhs._name;
//         _hitPoints =
//        _energyPoints = rhs._energyPoints;
//         _attackDamage = rhs._attackDamage;
//     }
//     std::cout << "ScavTrap assignment operator called." << std::endl;
//     return (*this);
// }
// Cat& Cat::operator=(const Cat& rhs) {
//     if (this != &rhs) {
//         Animal::operator=(rhs); // 기본 클래스 부분의 상태를 복사
//         // Cat 클래스의 멤버 변수에 대한 복사 로직 (현재는 없음)
//         std::cout << "Cat assignment operator called." << std::endl;
//     }
//     return *this;
// }
// #ifndef DOG_HPP
// #define DOG_HPP

// #include "Animal.hpp"

// class Dog : public Animal {
// public:
//     Dog(); // 기본 생성자
//     Dog(const Dog& src); // 복사 생성자
//     Dog& operator=(const Dog& rhs); // 대입 연산자 오버로딩
//     virtual ~Dog(); // 소멸자

//     virtual void makeSound() const; // 가상 함수 오버라이딩
// };

// #endif // DOG_HPP
// #include "Dog.hpp"
// #include <iostream>

// // 기본 생성자
// Dog::Dog() : Animal("Dog") {
//     std::cout << "Dog constructor called." << std::endl;
// }

// // 복사 생성자
// Dog::Dog(const Dog& src) : Animal(src) {
//     std::cout << "Dog copy constructor called." << std::endl;
// }

// // 대입 연산자 오버로딩
// Dog& Dog::operator=(const Dog& rhs) {
//     if (this != &rhs) {
//         Animal::operator=(rhs);
//     }
//     std::cout << "Dog assignment operator called." << std::endl;
//     return *this;
// }

// // 소멸자
// Dog::~Dog() {
//     std::cout << "Dog destructor called." << std::endl;
// }

// // makeSound 함수 오버라이딩
// void Dog::makeSound() const {
//     //"바우와우(Bow Wow)"
//     std::cout << "Dog:  Woof" << std::endl;
// }


// #ifndef WRONGANIMAL_HPP
// #define WRONGANIMAL_HPP

// #include <iostream>
// #include <string>

// class WrongAnimal {
// protected:
//     std::string type;

// public:
//     // WrongAnimal(); // 기본 생성자
//     WrongAnimal(const std::string &type); // 매개변수를 받는 생성자
//     WrongAnimal(const WrongAnimal& src); // 복사 생성자
//     WrongAnimal& operator=(const WrongAnimal& rhs); // 대입 연산자 오버로딩
//     virtual ~WrongAnimal(); // 소멸자

//     void makeSound() const; // 가상 함수가 아닌 일반 멤버 함수
//     std::string getType() const; // 동물의 종류를 반환하는 함수
// };

// #endif // WRONGANIMAL_HPP
#include "WrongAnimal.hpp"

// 기본 생성자
// WrongAnimal::WrongAnimal() : type("WrongAnimal") {
//     std::cout << "WrongAnimal default constructor called." << std::endl;
// }

// // 매개변수를 받는 생성자
// WrongAnimal::WrongAnimal(const std::string &type) : type(type) {
//     std::cout << "WrongAnimal constructor with type called." << std::endl;
// }

// // 복사 생성자
// WrongAnimal::WrongAnimal(const WrongAnimal& src) : type(src.type) {
//     std::cout << "WrongAnimal copy constructor called." << std::endl;
// }

// // 대입 연산자 오버로딩
// WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
//     if (this != &rhs) {
//         this->type = rhs.type;
//     }
//     std::cout << "WrongAnimal assignment operator called." << std::endl;
//     return *this;
// }

// // 소멸자
// WrongAnimal::~WrongAnimal() {
//     std::cout << "WrongAnimal destructor called." << std::endl;
// }

// // makeSound 함수
// void WrongAnimal::makeSound() const {
//     std::cout << "WrongAnimal makes a sound!" << std::endl;
// }

// // getType 함수
// std::string WrongAnimal::getType() const {
//     return type;
// }
// #ifndef WRONGCAT_HPP
// #define WRONGCAT_HPP

// #include "WrongAnimal.hpp"

// class WrongCat : public WrongAnimal {
// public:
//     WrongCat();
//     WrongCat(const WrongCat& src);
//     WrongCat& operator=(const WrongCat& rhs);
//     virtual ~WrongCat();
// };

// #endif // WRONGCAT_HPP


// #include "WrongCat.hpp"
// #include <iostream>

// WrongCat::WrongCat() {
//     type = "WrongCat";
//     std::cout << "WrongCat constructor called." << std::endl;
// }

// WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
//     std::cout << "WrongCat copy constructor called." << std::endl;
// }

// WrongCat& WrongCat::operator=(const WrongCat& rhs) {
//     if (this != &rhs) {
//         WrongAnimal::operator=(rhs);
//     }
//     std::cout << "WrongCat assignment operator called." << std::endl;
//     return *this;
// }

// WrongCat::~WrongCat() {
//     std::cout << "WrongCat destructor called." << std::endl;
// }


// ex01
// #ifndef BRAIN_H
// #define BRAIN_H

// #include <string>

// class Brain {
// private:
//     std::string ideas[100]; // 아이디어를 저장하는 배열

// public:
//     Brain(); // 기본 생성자
//     Brain(const Brain& other); // 복사 생성자
//     Brain& operator=(const Brain& other); // 대입 연산자 오버로딩
//     ~Brain(); // 소멸자

//     // 기타 멤버 함수들...
//     std::string getIdea(int index) const; // 특정 인덱스의 아이디어를 반환하는 함수
//     void setIdea(int index, const std::string& idea); // 특정 인덱스에 아이디어를 설정하는 함수
// };

// #endif // BRAIN_H

// #include "Brain.hpp"
// #include <iostream>

// // 기본 생성자
// Brain::Brain() {
//     std::cout << "Brain object created." << std::endl; // 객체가 생성될 때 메시지 출력
// }

// // 복사 생성자
// Brain::Brain(const Brain& src) {
//     *this = src;
//     std::cout << "Brain object copied." << std::endl; // 복사 생성될 때 메시지 출력
// }

// // 대입 연산자 오버로딩
// Brain& Brain::operator=(const Brain& rhs) {
//     if (this != &rhs) { // 자기 자신에게 할당하는 경우를 방지
//         for (int i = 0; i < 100; i++) {
//             this->ideas[i] = rhs.ideas[i];
//         }
//     }
//     return *this; 
// }

// // 소멸자
// Brain::~Brain() {
//     std::cout << "Brain object destroyed." << std::endl; // 객체가 소멸될 때 메시지 출력
// }

// // ideas 배열의 특정 인덱스에 저장된 아이디어를 반환하는 함수
// std::string Brain::getIdea(int idx) const {
//     if (idx >= 0 && idx < 100) {
//         return ideas[idx];
//     } else {
//         std::cout << "Index out of bounds" << std::endl;
//         return ""; // 잘못된 인덱스 접근 시, 빈 문자열 반환
//     }
// }

// // ideas 배열의 특정 인덱스에 새로운 아이디어를 저장하는 함수
// void Brain::setIdea(int index, const std::string& idea) {
//     if (index >= 0 && index < 100) {
//         ideas[index] = idea;
//     } else {
//         std::cout << "Index out of bounds" << std::endl; // 잘못된 인덱스 접근 시 경고
//     }
// }

// #ifndef DOG_HPP
// #define DOG_HPP

// #include "Animal.hpp"
// #include "Brain.hpp" // Brain 클래스 포함
// #include <iostream>

// class Dog : public Animal {
// private:
//     Brain* brain; // Brain 포인터 추가

// public:
//     Dog();
//     Dog(const Dog& src);
//     Dog& operator=(const Dog& rhs);
//     virtual ~Dog();

//     virtual void makeSound() const;
// };

// #endif

// // Dog.cpp 파일
// #include "Dog.hpp"

// Dog::Dog() : Animal("Dog"), brain(new Brain()) {
//     std::cout << "Dog constructor called." << std::endl;
// }

// Dog::Dog(const Dog& src) : Animal(src), brain(new Brain(*src.brain)) {
//     std::cout << "Dog copy constructor called." << std::endl;
// }

// Dog& Dog::operator=(const Dog& rhs) {
//     if (this != &rhs) {
//         Animal::operator=(rhs);
//         delete brain; // 기존 Brain 객체 해제
//         brain = new Brain(*rhs.brain); // 새 Brain 객체 할당
//     }
//     std::cout << "Dog assignment operator called." << std::endl;
//     return *this;
// }

// Dog::~Dog() {
//     delete brain; // Brain 객체 해제
//     std::cout << "Dog destructor called." << std::endl;
// }

// void Dog::makeSound() const {
//     std::cout << "Dog: Bow Wow" << std::endl;
// }

// TODO: 캣 클래스도 도그 클래스처럼 바꾸기


// #include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"
// #include <iostream>

// int main() {
//     std::cout << "------ Testing Animal Class ------" << std::endl;

//     // Animal 객체의 배열을 생성합니다.
//     // 여기서는 Animal 포인터의 배열을 사용합니다.
//     const int SIZE = 10; // 배열의 크기
//     Animal* animals[SIZE];

//     // 배열의 절반을 Dog 객체로 채웁니다.
//     for (int i = 0; i < SIZE / 2; ++i) {
//         animals[i] = new Dog();
//         std::cout << "Dog " << i + 1 << " created." << std::endl;
//     }

//     // 배열의 나머지 절반을 Cat 객체로 채웁니다.
//     for (int i = SIZE / 2; i < SIZE; ++i) {
//         animals[i] = new Cat();
//         std::cout << "Cat " << (i - SIZE / 2) + 1 << " created." << std::endl;
//     }

//     std::cout << "------ All animals created ------" << std::endl;

//     // 모든 동물이 소리를 냅니다.
//     for (int i = 0; i < SIZE; ++i) {
//         animals[i]->makeSound();
//     }

//     std::cout << "------ Deleting all animals ------" << std::endl;

//     // 배열에 저장된 모든 Animal 객체를 삭제합니다.
//     for (int i = 0; i < SIZE; ++i) {
//         delete animals[i]; // 이 과정에서 Dog와 Cat의 소멸자가 호출됩니다.
//         std::cout << "Animal " << i + 1 << " deleted." << std::endl;
//     }

//     return 0;
// }

// #ifndef AMATERIA_H
// #define AMATERIA_H

// #include <iostream>
// #include <string>

// // AMateria 클래스 정의
// class AMateria {
// protected:
//     std::string type; // 마테리아의 타입

// public:
//     // 기본 생성자
//     AMateria(std::string const &type);
    
//     // 복사 생성자
//     AMateria(AMateria const &src);
    
//     // 대입 연산자 오버로딩
//     AMateria &operator=(AMateria const &rhs);
    
//     // 소멸자
//     virtual ~AMateria();


//     // 타입을 반환하는 함수
//     std::string const &getType() const; // 마테리아 타입 반환

//     // 순수 가상 함수 - 복제를 위한 함수
//     virtual AMateria* clone() const = 0;

//     // 순수 가상 함수 - 사용을 위한 함수
//     virtual void use() = 0;
// };

// #endif // AMATERIA_H

// #include "AMateria.h"

// // 생성자
// AMateria::AMateria(std::string const &type) : type(type) {}

// // 복사 생성자
// AMateria::AMateria(AMateria const &src) : type(src.type) {}

// // 복사 할당 연산자
// AMateria &AMateria::operator=(AMateria const &rhs) {
//     // 자기 자신에 대한 할당을 체크
//     if (this != &rhs) {
//         this->type = rhs.type;
//     }
//     return *this;
// }

// // 소멸자
// AMateria::~AMateria() {}

// // 타입 반환 함수
// std::string const &AMateria::getType() const {
//     return this->type;
// }

// // 주의: clone()과 use() 함수는 여기에 구현되지 않습니다.
// // 이는 상속받은 구체 클래스에서 구현되어야 합니다.

// #ifndef ICE_H
// #define ICE_H

// #include "AMateria.h"
// #include "ICharacter.h"
// #include <string>

// class Ice : public AMateria {
// public:
//     Ice(); // 기본 생성자
//     Ice(Ice const &src); // 복사 생성자
//     Ice &operator=(Ice const &rhs); // 복사 할당 연산자
//     virtual ~Ice(); // 소멸자

//     // AMateria의 순수 가상 함수를 구현
//     virtual Ice* clone() const; // 자신의 인스턴스를 복제하는 함수
//     virtual void use(ICharacter& target); // 특정 캐릭터를 대상으로 마법을 사용하는 함수
// };

// #endif

// #ifndef ICHARACTER_HPP
// #define ICHARACTER_HPP

// #include <string>
// // AMateria 클래스를 전방 선언합니다. 
// // 이는 ICharacter와 AMateria가 서로를 include하게 되는 상황을 방지하기 위함입니다.
// class AMateria;

// class ICharacter {
// public:
//     virtual ~ICharacter() {} // 가상 소멸자

//     // 캐릭터의 이름을 반환하는 순수 가상 함수
//     virtual std::string const &getName() const = 0;

//     // 마법(Materia)을 장착하는 순수 가상 함수
//     virtual void equip(AMateria* m) = 0;

//     // 마법(Materia)을 장착 해제하는 순수 가상 함수
//     virtual void unequip(int idx) = 0;

//     // 특정 대상에게 마법(Materia)을 사용하는 순수 가상 함수
//     virtual void use(int idx, ICharacter& target) = 0;
// };

// #endif
/*getName() const: 캐릭터의 이름을 반환합니다. 이는 모든 캐릭터가 고유한 이름을 가지고 있음을 나타냅니다.
equip(AMateria* m): 특정 마법(Materia)을 캐릭터에 장착합니다. 캐릭터는 여러 마법을 장착할 수 있으며, 이를 통해 전투 또는 기타 상황에서 사용할 수 있습니다.
unequip(int idx): 지정된 인덱스에 있는 마법(Materia)을 장착 해제합니다. 장착 해제된 마법은 삭제되지 않고, 나중에 다시 사용할 수 있습니다.
use(int idx, ICharacter& target): 지정된 인덱스에 있는 마법(Materia)을 사용하여, 주어진 대상(target)에게 특정 효과를 적용합니다. 이는 공격, 치유 등 다양한 효과를 포함할 수 있습니다.*/

// #ifndef CHARACTER_HPP
// #define CHARACTER_HPP

// #include "ICharacter.hpp"
// #include "AMateria.hpp"
// #include <string>

// // Character 클래스는 ICharacter 인터페이스를 구현합니다.
// class Character : public ICharacter {
// private:
//     std::string name; // 캐릭터의 이름
//     AMateria* inventory[4]; 

// public:
//     // 기본 생성자
//     Character(std::string const &name);
//     // 복사 생성자
//     Character(Character const &other);
//     // 복사 할당 연산자
//     Character &operator=(Character const &rhs);
//     // 소멸자
//     virtual ~Character();

//     // ICharacter 인터페이스 구현
//     // 캐릭터의 이름을 반환합니다.
//     virtual std::string const &getName() const;
//     // 특정 마법(Materia)을 장착합니다.
//     virtual void equip(AMateria* m);
//     // 마법(Materia)을 장착 해제합니다.
//     virtual void unequip(int idx);
//     // 특정 대상에게 마법(Materia)을 사용합니다.
//     virtual void use(int idx, ICharacter& target);

// };

// #endif // CHARACTER_HPP

// #include "Character.hpp"
// #include <iostream>

// //The inventory is empty at construction. 
// Character::Character(std::string const &name) : name(name) {
//     for (int i = 0; i < 4; ++i) {
//         inventory[i] = NULL;
//     }
// }

// Character::Character(Character const &src) : name(src.name) {
//     for (int i = 0; i < 4; ++i) {
//         if (src.inventory[i])
//             inventory[i] = src.inventory[i]->clone();
//         else
//             inventory[i] = NULL;
//     }
// }

// Character &Character::operator=(Character const &rhs) {
//     if (this != &rhs) {
//         name = rhs.name;
//         for (int i = 0; i < 4; ++i) {
//             delete inventory[i];
//             if (rhs.inventory[i])
//                 inventory[i] = rhs.inventory[i]->clone();
//             else
//                 inventory[i] = NULL;
//         }
//     }
//     return *this;
// }

// Character::~Character() {
//     for (int i = 0; i < 4; ++i) {
//         delete inventory[i];
//     }
// }

// std::string const &Character::getName() const {
//     return name;
// }

// void Character::equip(AMateria* m) {
//     for (int i = 0; i < 4; ++i) {
//         if (!inventory[i]) {
//             inventory[i] = m;
//             break;
//         }
//     }
// }

// void Character::unequip(int idx) {
//     if (idx >= 0 && idx < 4) {
//         inventory[idx] = NULL;
//     }
// }

// void Character::use(int idx, ICharacter& target) {
//     if (idx >= 0 && idx < 4 && inventory[idx]) {
//         inventory[idx]->use(target);
//     }
// }

// #include "Character.hpp"
// #include <iostream>

// // 생성자: 인벤토리를 비워둠
// Character::Character(std::string const &name) {
//     this->name = name; // 이름 할당
//     for (int i = 0; i < 4; ++i) {
//         inventory[i] = NULL; // 인벤토리 초기화
//     }
// }

// // 복사 생성자: 다른 캐릭터 객체로부터 깊은 복사를 수행
// Character::Character(Character const &src) {
//     name = src.name; // 이름 복사
//     for (int i = 0; i < 4; ++i) {
//         if (src.inventory[i])
//             inventory[i] = src.inventory[i]->clone(); // Materia 복제
//         else
//             inventory[i] = NULL; // NULL로 초기화
//     }
// }

// // 복사 할당 연산자: 다른 캐릭터 객체의 상태를 현재 객체에 할당
// Character &Character::operator=(Character const &rhs) {
//     if (this != &rhs) { // 자기 자신에 대한 할당 방지
//         name = rhs.name; // 이름 할당
//         for (int i = 0; i < 4; ++i) {
//             delete inventory[i]; // 기존 Materia 삭제
//             if (rhs.inventory[i])
//                 inventory[i] = rhs.inventory[i]->clone(); // Materia 복제
//             else
//                 inventory[i] = NULL; // NULL로 초기화
//         }
//     }
//     return *this;
// }

// // 소멸자: 할당된 모든 Materia 삭제
// Character::~Character() {
//     for (int i = 0; i < 4; ++i) {
//         delete inventory[i]; // Materia 삭제
//     }
// }

// // 캐릭터의 이름 반환
// std::string const &Character::getName() const {
//     return name;
// }

// // Materia 장착: 첫 번째 빈 슬롯에 Materia 추가
// void Character::equip(AMateria* m) {
//     for (int i = 0; i < 4; ++i) {
//         if (!inventory[i]) { // 빈 슬롯 찾기
//             inventory[i] = m; // Materia 추가
//             break;
//         }
//     }
// }

// // Materia 장착 해제: 지정된 인덱스의 Materia 제거하지만 삭제하지는 않음
// void Character::unequip(int idx) {
//     if (idx >= 0 && idx < 4) { // 유효한 인덱스 확인
//         inventory[idx] = NULL; // Materia 제거
//     }
// }

// // 사용: 지정된 인덱스의 Materia를 사용하여 대상에게 효과 적용
// void Character::use(int idx, ICharacter& target) {
//     if (idx >= 0 && idx < 4 && inventory[idx]) { // 유효한 인덱스와 Materia 존재 확인
//         inventory[idx]->use(target); // Materia 사용
//     }
// }


// #include "Ice.hpp"
// #include <iostream>

// Ice::Ice() {
//     // 생성자 본문에서 초기화
//     type = "ice"; // 마법의 타입을 "ice"로 설정
// }

// Ice::Ice(Ice const &src) : AMateria(src) {
//     // 복사 생성자 본문에서 초기화, AMateria 부분은 기반 클래스의 복사 생성자 호출
// }

// Ice &Ice::operator=(Ice const &rhs) {
//     // 할당 연산자
//     if (this != &rhs) {
//         AMateria::operator=(rhs); // 기반 클래스의 할당 연산자 호출
//     }
//     return *this;
// }

// Ice::~Ice() {
//     // 소멸자에서 특별한 처리가 필요하지 않음
// }

// Ice* Ice::clone() const {
//     return new Ice(*this); // Ice 객체의 복사본을 생성하여 반환
// }

// void Ice::use(ICharacter& target) {
//     std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
// }

// #include "Ice.hpp"
// #include <iostream>

// // 기본 생성자
// Ice::Ice() {
//     // 생성자 본문에서 값 할당
//     this->type = "ice"; // "ice" 타입으로 초기화
//     std::cout << "Ice default Constructor called." << std::endl;
// }

// // 복사 생성자
// Ice::Ice(Ice const &src) : AMateria(src) {
//     // 복사 생성자 본문에서 값 할당 (기반 클래스의 복사 생성자 호출)
//     std::cout << "Ice copy Constructor called." << std::endl;
// }

// // 대입 연산자
// Ice &Ice::operator=(Ice const &rhs) {
//     if (this != &rhs) {
//         AMateria::operator=(rhs); // 기반 클래스의 대입 연산자 호출
//         // 추가적인 자원 복사가 필요 없음
//     }
//     std::cout << "Ice assignment operator called." << std::endl;
//     return *this;
// }

// // 소멸자
// Ice::~Ice() {
//     std::cout << "Ice Destructor called." << std::endl;
// }



// // clone 함수 구현
// Ice* Ice::clone() const {
//     return new Ice(*this); // Ice 객체의 복사본을 생성하여 반환
// }

// // use 함수 구현
// void Ice::use(ICharacter& target) {
//     std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
//     // 특정 캐릭터를 대상으로 마법을 사용하는 함수 구현
// }


// // AMateria
// class AMateria {
// protected:
//     std::string type; // 마법의 타입을 저장

// public:
//     // 타입을 인자로 받는 생성자
//     AMateria(std::string const& type) : type(type) {}

//     // 복사 생성자
//     AMateria(AMateria const &src) : type(src.type) {}

//     // 대입 연산자
//     AMateria &operator=(AMateria const &rhs) {
//         if (this != &rhs) {
//             this->type = rhs.type;
//         }
//         return *this;
//     }

//     // 가상 소멸자
//     virtual ~AMateria() {}


//     // 타입을 반환하는 멤버 함수
//     std::string const &getType() const {
//         return type;
//     }

//     // 순수 가상 함수 - 복제를 위한 함수
//     virtual AMateria* clone() const = 0;

//     // 순수 가상 함수 - 사용을 위한 함수, ICharacter 타입의 참조를 매개변수로 받도록 수정
//     virtual void use(ICharacter& target) = 0;
// };
// #include "AMateria.hpp"
// #include <iostream>

// // 기본 생성자
// AMateria::AMateria() : type("") {
//     // 기본 생성자에서는 타입을 빈 문자열로 초기화합니다.
// }

// // 타입을 인자로 받는 생성자
// AMateria::AMateria(std::string const& type) : type(type) {
//     // 이 생성자는 마법의 타입을 설정합니다.
// }

// // 복사 생성자
// AMateria::AMateria(AMateria const &src) : type(src.type) {
//     // 복사 생성자는 다른 AMateria 객체로부터 타입을 복사하여 초기화합니다.
// }

// // 대입 연산자
// AMateria& AMateria::operator=(AMateria const &rhs) {
//     // 대입 연산자는 자기 자신에 대한 대입을 체크하고, 타입을 복사합니다.
//     if (this != &rhs) {
//         this->type = rhs.type;
//     }
//     return *this;
// }

// // 소멸자
// AMateria::~AMateria() {
//     // 가상 소멸자는 파생 클래스에서의 적절한 자원 해제를 보장합니다.
// }

// // 타입을 반환하는 함수
// std::string const& AMateria::getType() const {
//     // 이 함수는 AMateria 객체의 타입을 반환합니다.
//     return type;
// }

// #ifndef CURE_HPP
// #define CURE_HPP

// #include "AMateria.hpp"
// #include "ICharacter.hpp"
// #include <iostream>

// class Cure : public AMateria {
// public:
//     Cure();
//     Cure(Cure const &src);
//     Cure &operator=(Cure const &rhs);
//     virtual ~Cure();

//     virtual Cure* clone() const ;
//     virtual void use(ICharacter& target) ;
// };

// #endif // CURE_HPP

// #include "Cure.hpp"

// Cure::Cure() {
//     this->type = "cure"; // 타입을 "cure"로 초기화
//     std::cout << "Cure default Constructor called." << std::endl;
// }

// Cure::Cure(Cure const &src) : AMateria(src) {
//     std::cout << "Cure copy Constructor called." << std::endl;
// }

// Cure &Cure::operator=(Cure const &rhs) {
//     if (this != &rhs) {
//         AMateria::operator=(rhs); // 기본 클래스의 대입 연산자 호출
//     }
//     std::cout << "Cure assignment operator called." << std::endl;
//     return *this;
// }

// Cure::~Cure() {
//     std::cout << "Cure Destructor called." << std::endl;
// }

// Cure* Cure::clone() const {
//     return new Cure(*this); // Cure 객체의 복사본을 생성하여 반환
// }

// void Cure::use(ICharacter& target) {
//     std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
//     // 특정 캐릭터를 대상으로 치유 마법을 사용하는 함수 구현
// }
