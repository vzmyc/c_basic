# 구조체 비트 필드 사용하기  

비트 필드는 다음과 같이 멤버를 선언할 때 : (콜론) 뒤에 비트 수를 지정해주면 됩니다.  
<pre><code>
struct 구조체이름 {
    정수자료형 멤버이름 : 비트수;
};
</code></pre>

 ex>
 <pre>// struct_bit_field.c<code>
#include <stdio.h>

struct Flags {
    unsigned int a : 1;     // a는 1비트 크기
    unsigned int b : 3;     // b는 3비트 크기
    unsigned int c : 7;     // c는 7비트 크기
};

int main()
{
    struct Flags f1;    // 구조체 변수 선언

    f1.a = 1;      //   1: 0000 0001, 비트 1개
    f1.b = 15;     //  15: 0000 1111, 비트 4개
    f1.c = 255;    // 255: 1111 1111, 비트 8개

    printf("%u\n", f1.a);    //   1:        1, 비트 1개만 저장됨
    printf("%u\n", f1.b);    //   7:      111, 비트 3개만 저장됨
    printf("%u\n", f1.c);    // 127: 111 1111, 비트 7개만 저장됨

    return 0;
}
 </code></pre>

실행 결과  
1  
7  
127  

---
비트 필드에는 지정한 비트 수만큼 저장되며 나머지 비트는 버려집니다. 따라서 a는 비트 그대로 1만 저장되었고, b는 비트 3개만 저장되었으므로 7, c는 비트 7개만 저장되었으므로 127이 됩니다.
다음과 같이 비트 필드의 각 멤버는 최하위 비트(Least Significant Bit, LSB)부터 차례대로 배치됩니다. 따라서 a가 최하위 비트에 오고 나머지 멤버들은 각각 상위비트에 배치됩니다.  



ex2>  
 <pre>// struct_bit_field_sizeof.c<code>
#include <stdio.h>

struct Flags {
    unsigned int a : 1;    // a는 1비트 크기
    unsigned int b : 3;    // b는 3비트 크기
    unsigned int c : 7;    // c는 7비트 크기
};

int main()
{
    printf("%d", sizeof(struct Flags));    // 4: 멤버를 unsigned int로 선언했으므로 4

    return 0;
}
  </code></pre>
실행 결과  
4  

---  
비트 필드의 멤버를 unsigned int로 선언했으므로 구조체의 크기는 4가 됩니다. 만약 멤버를 unsigned short로 선언하면 구조체의 크기는 2가 나옵니다.  



<pre>다음과 같이 비트 필드의 멤버를 선언하는 자료형보다 큰 비트 수는 지정할 수 없습니다.<code>
struct Flags {
    unsigned int a : 37;    // 컴파일 에러.
    unsigned int b : 3;
    unsigned int c : 7;
};
</code></pre>