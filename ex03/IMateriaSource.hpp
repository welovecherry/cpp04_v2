/* `IMateriaSource` 인터페이스는 마법 재료(`AMateria`)를 학습하고 생성하는 데 필요한 메커니즘을 정의합니다. 
여기서 "학습"한다는 것은 마법 재료의 정보를 저장해 두었다가, 필요할 때 해당 마법 재료의 복사본을 만들어내는 것을 의미합니다. 

이 인터페이스를 구현하는 구체 클래스(`MateriaSource`)는 마법 재료를 관리하는 역할을 합니다. 
`IMateriaSource` 인터페이스의 주요 기능을 간단히 설명하면 다음과 같습니다:

### 1. `learnMateria(AMateria*)`
- 이 함수는 `AMateria` 객체(즉, 마법 재료)를 인자로 받아서, 그 정보를 내부적으로 저장합니다.
- 예를 들어, 얼음(`Ice`) 마법 재료나 치유(`Cure`) 마법 재료 같은 구체적인 마법 재료들이 이 함수를 통해 학습될 수 있습니다.
- `MateriaSource`는 최대 4개의 마법 재료를 알고 있을 수 있으며, 이들은 고유하지 않아도 됩니다. 
즉, 같은 타입의 마법 재료를 여러 번 학습할 수 있습니다.

### 2. `createMateria(std::string const &type)`
- 이 함수는 주어진 마법 재료의 타입(`type`)에 해당하는 마법 재료의 새로운 인스턴스를 생성하여 반환합니다.
- `learnMateria`를 통해 학습된 마법 재료 중에서, 요청된 `type`과 일치하는 마법 재료를 찾아 그 복사본을 만들어 반환합니다.
- 만약 요청된 `type`의 마법 재료를 학습하지 않았다면, ``을 반환합니다.

간단히 말해, `IMateriaSource` 인터페이스(및 이를 구현하는 `MateriaSource` 클래스)는 
마법 재료(`AMateria`)의 "도서관"과 같은 역할을 합니다. 

여러분이 마법 재료를 "체크아웃"하려 할 때, 그 마법 재료의 타입을 지정하면, 도서관은 해당 타입의 마법 재료를 복제하여 제공합니다. 
이 시스템을 통해, 게임의 다양한 부분에서 필요한 마법 재료를 효율적으로 생성하고 사용할 수 있습니다.*/

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class Amateria;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria *m) = 0;
		virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif