#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
// 추가됨
/* Brain *brain;을 사용하여 Dog 클래스 내에 멤버 변수로 포인터를 만든 이유는, 
동적으로 Brain 객체를 할당하고 관리하기 위함입니다.

- `Brain *brain;` 방식은 `Dog` 객체가 `Brain` 객체를 더 유연하게 관리할 수 있도록 합니다. 
예를 들어, `Dog` 객체가 동적으로 `Brain` 객체를 할당/해제하거나, 
실행 도중에 `Brain` 객체를 변경할 필요가 있는 경우에 적합합니다.

- 반면, `Brain &brain;` 참조 방식은 `Dog` 객체가 항상 유효한 `Brain` 객체를 가지고 있어야 하며, 
일단 설정되면 변경할 수 없다는 제약이 따릅니다. 
이는 `Brain` 객체의 생명 주기가 `Dog` 객체와 밀접하게 연결되어야 하는 경우에 적합할 수 있습니다.

따라서 `Brain *brain;`을 선택하는 것은 `Dog` 객체의 설계 의도에 따라 
`Brain` 객체를 더 유연하게 관리하려는 목적에서 비롯된 것으로 이해할 수 있습니다.*/
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog& src);
    Dog& operator=(const Dog& rhs);
    virtual ~Dog();

    virtual void makeSound() const; // 가상 함수 오버라이딩
};

#endif