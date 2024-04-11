#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

/* the default Animal class should not be instantiable. 
Fix the Animal class so nobody can instantiate it. */

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& src);
    Animal& operator=(const Animal& rhs);
    virtual ~Animal();

    //virtual void makeSound() const;
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif