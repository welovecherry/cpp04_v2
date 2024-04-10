#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
// 추가됨
private:
    Brain *brain;
public:
    Cat();
    Cat(const Cat& src);
    Cat& operator=(const Cat& rhs);
    virtual ~Cat();

    virtual void makeSound() const; // 가상함수 오버라이딩
};

#endif