#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

// Dog and Cat will have a private Brain* attribute.

class Cat : public Animal {
private:
    Brain *brain;
public:
    Cat();
    Cat(const Cat& src);
    Cat& operator=(const Cat& rhs);
    ~Cat();

    void makeSound() const;
};

#endif