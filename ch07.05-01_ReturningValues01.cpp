// ch07.05-01_ReturningValues01.cpp 
//
// 함수에 들어가는 인자들을 어떻게 넣어줄 것인가에 대해서 공부했었다. 
// 이번에는 반환 값을 어떻게 받을 것인가, 
// 즉 계산한 결과, 함수가 수행한 결과를 어떻게 돌려받을 것인가에 대해서 살펴본다.

// 가장 기본적인 값을 돌려받는 방법에 대해서 살펴보자. 

#include <iostream>

int getValue(int x) {
    int value = x * 2;
    return value;
}

int main()
{
    int value = getValue(3);

    std::cout << value << std::endl;

    return 0;
}

// 함수 안의 계산이 처리된 후 반환 값이 main() 함수의 value 변수에 복사가 된다. 
// 가장 간단하고 안전하다. 
// 단점은 복사를 하고, 변수가 생성이 되는 것이 여러 번 반복된다는 것이다.
// 아무래도 속도가 조금 떨어지게 된다. 
// 간단할 때야 큰 문제가 아니지만, structure나 class, array를 사용하면서, 
// 데이터가 엄청나게 많다면 매번 이렇게 복사를 하는 게 곤란하게 된다. 
// 그러므로, 
// 다음은 주소 값으로 돌려받는 것을 살펴보자. 
