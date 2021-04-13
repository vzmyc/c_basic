type_conversion_void_pointer
===============================
자료형 변환을 주로 사용하는 상황은 구조체 포인터를 변환할 때입니다.   
이때는 struct와 구조체 이름 뒤에 *을 붙여주고 괄호로 묶어주면 됩니다.    

* (struct 구조체이름 *)포인터  
* ((struct 구조체이름 *)포인터)->멤버  

# type_conversion_void_pointer.c
<pre><code>
#include <stdio.h>
int main()
{
    int num1 = 10;
    float num2 = 3.5f;
    char c1 = 'a';
    void *ptr;

    ptr = &num1;    // num1의 메모리 주소를 void 포인터 ptr에 저장
    // printf("%d\n", *ptr);         // 컴파일 에러
    printf("%d\n", *(int *)ptr);     // 10: void 포인터를 int 포인터로 변환한 뒤 역참조

    ptr = &num2;    // num2의 메모리 주소를 void 포인터 ptr에 저장
    // printf("%f\n", *ptr);         // 컴파일 에러
    printf("%f\n", *(float *)ptr);   // 3.500000: void 포인터를 float 포인터로 변환한 뒤 역참조

    ptr = &c1;      // c1의 메모리 주소를 void 포인터 ptr에 저장
    // printf("%c\n", *ptr);         // 컴파일 에러
    printf("%c\n", *(char *)ptr);    // a: void 포인터를 char 포인터로 변환한 뒤 역참조

    return 0;
}

// 실행 결과
10
3.500000
a
</code></pre>
---

ptr = &num1;과 같이 int형 변수 num1의 메모리 주소를 ptr에 저장했습니다.  
하지만 ptr은 void 포인터라 역참조를 하면 컴파일 에러가 발생합니다.  
따라서 *(int *)ptr와 같이 void 포인터를 int 포인터로 변환한 뒤 역참조를 해야 합니다.

<pre>
type_conversion_void_pointer.c(11): error C2100: 간접 참조가 잘못되었습니다.
</pre>

마찬가지로 void 포인터에 float 포인터(메모리 주소)가 들어있다면 *(float *)ptr와 같이 float 포인터로 변환한 뒤 역참조를 해야하고, char 포인터가 들어있다면 *(char *)ptr와 같이 char 포인터로 변환한 뒤 역참조를 해야 합니다.