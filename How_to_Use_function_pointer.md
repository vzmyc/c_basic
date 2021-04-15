# return값과 parameter 있는  함수포인터  

* 함수 포인터를 선언할 때, 반환값 type과 parameter type만 지정.  
ex>  
//↓ 반환값 자료형  
int (*fp)(int, int);    
//    ↑      ↖ int형 매개변수 두 개  
// 함수 포인터 이름  
---

<pre>// function_pointer_return_parameter_type.c<code>
#include <stdio.h>
int add(int a, int b)    // int형 반환값, int형 매개변수 두 개
{
    return a + b;
}

int mul(int a, int b)    // int형 반환값, int형 매개변수 두 개
{
    return a * b;
}

int main()
{
    int (*fp)(int, int);    // int형 반환값, int형 매개변수 두 개가 있는 함수 포인터 fp 선언

    fp = add;                      // add 함수의 메모리 주소를 함수 포인터 fp에 저장
    printf("%d\n", fp(10, 20));    // 30: 함수 포인터로 add 함수를 호출하여 합을 구함

    fp = mul;                      // mul 함수의 메모리 주소를 함수 포인터 fp에 저장
    printf("%d\n", fp(10, 20));    // 200: 함수 포인터로 mul 함수를 호출하여 곱을 구함

    return 0;
}
</code></pre>

실행 결과  
30  
200  
  