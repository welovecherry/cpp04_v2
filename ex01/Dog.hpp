#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

// Dog and Cat will have a private Brain* attribute.

class Dog : public Animal {
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog& src);
    Dog& operator=(const Dog& rhs);
    virtual ~Dog();

    virtual void makeSound() const;
};

#endif