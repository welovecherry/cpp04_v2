#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& src);
    WrongAnimal& operator=(const WrongAnimal & rhs);
    virtual ~WrongAnimal();

    void makeSound() const; // 가상 함수가 아닌 일반 멤버 함수
    std::string getType() const;
};

#endif