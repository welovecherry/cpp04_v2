#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& src);
    Dog& operator=(const Dog& rhs);
    virtual ~Dog();

    virtual void makeSound() const; // 가상 함수 오버라이딩
};

#endif