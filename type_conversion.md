# 자료형 변환
C 언어에서는 자료형이 같거나 크기가 큰 쪽, 표현 범위가 넓은 쪽으로 저장하면 자동으로 변환이 됩니다.

```c
int num1 = 10;  
unsigned int num2 = num1;    // int와 unsigned int는 자료형이 같음  
long long num3 = num1;       // long long이 int보다 크기가 큼
```
하지만 자료형이 다르면서 크기가 작은 쪽, 표현 범위가 좁은 쪽으로 저장하면 컴파일 경고가 발생합니다. 예를 들어 실수에서 소수점 이하 자리를 버리는 기능을 구현하고자 실수를 정수로 저장했을 때 프로그래머가 의도한 상황이지만 컴파일 경고가 발생합니다.

```c
float num1 = 3.56f;
int num2 = num1;    // 실수형 값을 정수형 변수에 저장하여 컴파일 경고 발생
```  

컴파일 결과
```
warning C4244: '초기화 중': 'float'에서 'int'(으)로 변환하면서 데이터가 손실될 수 있습니다.
```

- 암시적 형변환, 형 확장  
char -> short -> int -> long -> long long -> float -> double -> long double

- 형변환(타입 캐스팅), 형 축소  
char <- short <- int <- long <- long long <- float <- double <- long double

## type_conversion_variable.c
```c
#include <stdio.h>

int main()
{
    int num1 = 32;
    int num2 = 7;
    float num3;

    num3 = num1 / num2;      // 컴파일 경고 발생
    printf("%f\n", num3);    // 4.000000

    num3 = (float)num1 / num2;    // num1을 float로 변환
    printf("%f\n", num3);         // 4.571429

    return 0;
}
```
  

실행 결과
```
4.000000
4.571429
```
num3 = num1 / num2;와 같이 정수 / 정수를 계산하면 정수(int) 4가 나오고 num3에는 4.0000000이 저장됩니다.  
이때 num3은 float형이라 int와 자료형이 달라서 다음과 같이 컴파일 경고가 발생합니다.

```
컴파일 결과
type_conversion_variable.c(9): warning C4244: '=': 'int'에서 'float'(으)로 변환하면서 데이터가 손실될 수 있습니다.
```

따라서 아래와 같이 num1을 float으로 변환해주고 계산하여 컴파일 경고가 발생하지 않도록 합니다.
```c
    num3 = (float)num1 / num2;    // num1을 float로 변환
    printf("%f\n", num3);         // 4.571429
```