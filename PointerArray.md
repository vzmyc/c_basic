# 포인터에 할당된 메모리를 배열처럼 사용하기
포인터를 배열처럼 사용하는 방법은 간단합니다.  
포인터에 malloc 함수로 메모리를 할당해주면 됩니다.  

* 자료형 *포인터이름 = malloc(sizeof(자료형) * 크기);  

## pointer_like_array.c
``` c
#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{
    int *numPtr = malloc(sizeof(int) * 10);    // int 10개 크기만큼 동적 메모리 할당

    numPtr[0] = 10;    // 배열처럼 인덱스로 접근하여 값 할당
    numPtr[9] = 20;    // 배열처럼 인덱스로 접근하여 값 할당

    printf("%d\n", numPtr[0]);    // 배열처럼 인덱스로 접근하여 값 출력
    printf("%d\n", numPtr[9]);    // 배열처럼 인덱스로 접근하여 값 출력

    free(numPtr);    // 동적으로 할당한 메모리 해제

    return 0;
}
```
<pre>
실행 결과  
10  
20  
</pre>
int *numPtr = malloc(sizeof(int) * 10);과 같이 int 크기에 10을 곱하여 동적으로 메모리를 할당합니다(sizeof(int)를 곱하지 않으면 배열처럼 사용할 수 없습니다). 그리고 배열처럼 [ ] 안에 인덱스를 지정하여 값을 할당하거나 가져올 수 있습니다. 즉, 배열과 메모리가 할당된 포인터는 생성 방법만 다를 뿐 값을 다루는 방법은 같습니다.

## 포인터[인덱스]  
``` c
int numArr[10];                           // int형 요소 10개를 가진 배열 생성  
int *numPtr = malloc(sizeof(int) * 10);   // int 10개 크기만큼 메모리 할당  

numArr[0] = 10;    // 배열을 인덱스로 접근하여 값 할당  
numPtr[0] = 10;    // 포인터를 인덱스로 접근하여 값 할당  

free(numPtr);   // 메모리 해제  
```
단, 배열 numArr은 한 번 선언하면 끝이지만, 
포인터 numPtr은 malloc 함수로 메모리를 할당했기 때문에 free함수로 해제해줍니다.  

*numPtr처럼 포인터를 역참조한 것과 numPtr[0] 인덱스 0에 접근한 것은 같은 값을 가져옵니다.  
그리고 numPtr[1] 과 *(numPtr + 1)도 같은 값을 가져오는데 *(numPtr + 1)와 같이 포인터에 값을 더하는 방식을 포인터 연산이라고 합니다.
