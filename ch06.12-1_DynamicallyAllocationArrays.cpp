// ch06.12-1_DynamicallyAllocationArrays.cpp
//
/*
앞에서 배웠던 정적 array는 그 배열의 사이즈가
컴파일 타임에 결정이 돼 있었어야 사용할 수 있었다.
동적 할당 배열은 런 타임에 배열의 사이즈를 결정하고
그때 그때 메모리를 os로부터 받아오기 때문에 좀 더 유동적으로 사용할 수 있다.
동적 할당 배열에 대해서 살펴 보자.
*/

#include <iostream>
using namespace std;

int main()
{
    const int length9 = 5;

    int array9[length9]; // 정적 배열에서는 원소가 몇 개가 들어갈지가 const로 들어가야 한다.
                        // 즉 컴파일 타임에 딱 고정이 돼 있어야 한다. const를 안 쓰면 에러.

    //// 동적 할당 배열을 사용해 보자.
    int length;

    cin >> length;

    int* array = new int[length];

    array[0] = 1;
    array[1] = 2;

    for (int i = 0; i < length; ++i)
    {
        cout << (uintptr_t) & array[i] << endl;
        cout << array[i] << endl;
    }

    delete[] array;             // 이렇게 습관적으로 delete을 해 준다.
    /*
    5                   <- 입력을 5로 했다. 2 이상 입력해야 한다. 1을 입력하면 에러.
    15494712
    1
    15494716
    2
    15494720
    - 842150451         <- 값을 넣어 주지 않았으므로 쓰레기 값이 출력된다.
    15494724
    - 842150451         <- 값을 넣어 주지 않았으므로 쓰레기 값이 출력된다.
    15494728
    - 842150451         <- 값을 넣어 주지 않았으므로 쓰레기 값이 출력된다.
    */
    // cin 입력에 10000개를 넣어도 된다.
    cout << endl;

    //// 초기화 방법
    int length1;

    cin >> length1;

    int* array1 = new int[length1]();       // 이렇게 뒤에 ()를 넣어주면 0으로 초기화된다.

    array1[0] = 1;
    array1[1] = 2;

    for (int i = 0; i < length1; ++i)
    {
        cout << (uintptr_t) & array1[i] << endl;
        cout << array1[i] << endl;
    }

    delete[] array1;
    /*
    5                   <- 입력을 5로 함.
    19994360
    1
    19994364
    2
    19994368
    0                   <- array1[2]에 0이 들어가 있음
    19994372
    0                   <- array1[3]에 0이 들어가 있음
    19994376
    0                   <- array1[4]에 0이 들어가 있음
    */

    /*
    //초기화는 uniform initialization도 된다.
    int* array1 = new int[length1]();
    int* array1 = new int[length1] {};      // 이렇게 해도 된다.

    //값을 넣을 때는?
    int* array1 = new int[length1](123);    // 괄호에 값을 넣을 수 없다. array이므로.
    int* array1 = new int[length1] {11, 22, 33, 44, 55, 66};    // 이렇게 하면 된다.
    */
    cout << endl;

    // uniform initialization
    int length2;

    cin >> length2;

    int* array2 = new int[length2] {11, 22, 33, 44, 55, 66};    // 원소를 6개 넣어 줬다.

    array2[0] = 1;      // index 0의 원소가 11에서 1로 바뀌었다.
    array2[1] = 2;      // index 1의 원소가 22에서 2로 바뀌었다.

    for (int i = 0; i < length2; ++i)
    {
        cout << (uintptr_t)&array2[i] << endl;
        cout << array2[i] << endl;
    }

    delete[] array2;
    /*
    10              <- 입력은 10으로 함. 만약 입력을 5로 하면 에러가 뜬다. 원소가 6개임.
    33067
    1               <- index 0
    33067
    2               <- index 1
    33067
    33              <- index 2에 들어간다.
    33067
    44              <- index 3
    33067
    55              <- index 4
    33067
    66              <- index 5
    33067
    0
    33067
    0
    33067
    0
    33067
    0
    */
    // 위에서 입력을 5로 하면, 메모리는 5개 받아왔는데
    // {11, 22, 33, 44, 55, 66}의 66을 넣어 주려고 하니
    // 이미 다른 프로그램에서 메모리를 사용하고 있어서 메모리 충돌이 생긴다.
    // 이 프로그램이 부여받지 못한 메모리를 사용하려고 하므로 에러가 뜬 것이다.
    // 동적 할당이 사용하기 조금 힘든 건 사실이다. 주의를 할 필요가 있다.

    // 다른 예제를 보자
    int fixedArray[] = { 1, 2, 3, 4, 5 };   // int fixedArray[5], 정적 array에서는,
                                            // 이렇게 배열 사이즈를 넣어줘도 되나 생략 가능

    // 동적 할당에서도 위처럼 되는지 보자.
    int* array3 = new int[5]{ 1, 2, 3, 4, 5 };   // 된다.

    delete[] array3;    // new를 써 줬으면, delete은 어딘가에 반드시 써 줘야 한다.
                        // new를 쓰면 반드시 delete을 해 준다. <- 머릿속에 꽉 박아 둬라.

    // 그러면 다음도 가능할까? 안 된다.
    // int* array3 = new int[]{ 1, 2, 3, 4, 5 };    <- 안 된다.
    // 컴파일 타임에 결정을 안 하려고 하는 것이다.
    // 원소에 맞춰서 사이즈를 알아서 넣어주면 좋겠지만 그렇게는 안 된다.
    // int* array3 = new int[3]{ 1, 2, 3, 4, 5 };   <- 안 된다. 원소가 5개인데 사이즈는 3.
    // <- 메모리는 3개를 받아왔는데 원소는 5개나 돼서, {4, 5}를 넣을 자리가 없다.

    //// resizing이 되는가?
    // 배열 사이즈가 3인데 추가로 데이터를 받아와야 해서 5로 바꿀 수 있는가?
    // 일단 직접적으로는 안 된다.
    // 더 큰 메모리를 받아온 다음에 원래 갖고 있던 것을 복사해서 집어 넣고,
    // 그 뒤에 새로 추가될 것을 덧붙이는 식으로 해야 한다. 조금 번거롭다.
    // 하지만 정적 array는 그런 번거로운 작업조차 안 된다.
    // 또 다른 방법이 있다.
    // OS에 메모리를 달라고 요청을 할 때, 지금 내가 3칸 쓰고 있는데,
    // 이 3칸을 유지하면서 뒤에 2칸을 더 줄 수 있나요? 라고 요청을 해 본다.
    // 해 보면, 될 수도 있고 안 될 수도 있다. 안 될 경우에는 다시 할당을 해야 한다.
    // 기회가 되면 다시 알려 주겠다.
    // 뒤에 std에 들어 있는 vector를 배울 텐데, vector에서 언급이 된다.
    // 내부적으로 위에서 다룬 것처럼 돌아가는구나, 뭘 조심해야 하는구나 이 정도 정리해 둬라.

    // 지금까지 배열을 동적 할당 받아서 사용하는 방법을 살펴 봤다.
    // 동적 할당 받은 array가 사용 방법은 정적 할당 받은 array와 거의 똑같음을 확인했다.
    // 대괄호를 사용해서 인덱싱하는 것도 똑같다.
    // 배열 강의에서 포인터 연산을 이용해서 배열에 접근하는 방법을 언급했다.
    // dynamic array에서도 포인터 연산을 이용해서 배열에 똑같이 접근할 수 있다.
    // 각자 한 번씩 해 봐라.

    return 0;
}