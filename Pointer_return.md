# Pointer return
```c
//return_pointer_warning.c
#include <stdio.h>

int *ten()    // int 포인터를 반환하는 ten 함수 정의
{
    int num1 = 10;   // num1은 함수 ten이 끝나면 사라짐

    return &num1;    // 함수에서 지역 변수의 주소를 반환하는 것은 잘못된 방법
} //        ↑ warning C4172: 지역 변수 또는 임시 변수의 주소를 반환하고 있습니다.

int main()
{
    int *numPtr;

    numPtr = ten();    // 함수를 호출하고 반환값을 numPtr에 저장

    printf("%d\n", *numPtr);    // 10: 값이 나오긴 하지만 이미 사라진 변수를 출력하고 있음

    return 0;
}
```
컴파일 결과  
return_pointer_warning.c(7): warning C4172: 지역 변수 또는 임시 변수의 주소를 반환하고 있습니다.  
먼저 함수 반환값의 자료형을 지정할 때 int *ten()과 같이 int 포인터로 지정했습니다. 그리고 변수를 선언하고 값을 할당한 뒤 변수의 메모리 주소를 반환합니다.
---

```c
//return_pointer.c
#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int *ten()    // int 포인터를 반환하는 ten 함수 정의
{
    int *numPtr = malloc(sizeof(int));    // int 크기만큼 동적 메모리 할당

    *numPtr = 10;    // 역참조로 10 저장

    return numPtr;   // 포인터 반환. malloc으로 메모리를 할당하면 함수가 끝나도 사라지지 않음
}

int main()
{
    int* numPtr;

    numPtr = ten();    // 함수를 호출하고 반환값을 numPtr에 저장

    printf("%d\n", *numPtr);    // 10: 메모리를 해제하기 전까지 안전함

    free(numPtr);    // 다른 함수에서 할당한 메모리라도 반드시 해제해야 함

    return 0;
}
```
실행 결과  
10  
메모리가 main이 아닌 다른 함수(ten)에서 할당되었다 하더라도 반드시 free 함수로 해제를 해줍니다. 왜냐하면 동적 메모리는 함수를 벗어나도 계속 유지되므로 메모리를 해제하지 않으면 그대로 메모리 누수가 발생합니다. 즉, 메모리가 어디서 할당되었는지는 상관없이 사용이 끝난 메모리는 반드시 해제를 해줍니다.
