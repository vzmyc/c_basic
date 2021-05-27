# Python lamda function
람다의 정의는 간단합니다.  
```py
# lambda 인자리스트: 표현식

>>> g = lambda x: x**2
>>> print(g(8))
64
>>>
>>> f = lambda x, y: x + y
>>> print(f(4, 4))
8
```

람다 함수의 사용법 예시
``` py
>>> def inc(n):
	return lambda x: x + n

>>> f = inc(2)
>>> g = inc(4)
>>> print(f(12))
14
>>> print(g(12))
16
>>> print(inc(2)(12))
14
```

---
## 1. map() 함수
람다 함수의 장점은 map() 함수와 함께 사용될 때 볼 수 있습니다.  map() 은 두 개의 인수를 가지는 함수입니다.

r = map(function, iterable, ...)

첫 번째 인자 function 는 함수의 이름 입니다.  
두 번째 인자 iterable은 한번에 하나의 멤버를 반환할 수 있는 객체 입니다.  
(list, str, tuple) map()함수는 function을 iterable의 모든 요소에 대해 적용합니다.  
그리고 function에 의해 변경된  iterator를 반환합니다.


```py
>>> a = [1,2,3,4]
>>> b = [17,12,11,10]
>>> list(map(lambda x, y:x+y, a,b))
[18, 14, 14, 14]
```
---
  
  
## 2. filter() 함수  
filter() 함수도 두 개의 인자를 가집니다.
```
r = filter(function, iterable)
```
filter에 인자로 사용되는 function은 처리되는 각각의 요소에 대해 Boolean 값을 반환합니다.   
True를 반환하면 그 요소는 남게 되고, False 를 반환하면 그 요소는 제거 됩니다.  

```py
>>> foo = [2, 18, 9, 22, 17, 24, 8, 12, 27]
>>> list( filter(lambda x: x % 3 == 0, foo) )
[18, 9, 24, 12, 27]
```

---

## 3. reduce() 함수
reduce() 함수를 두 개의 필수 인자와 하나의 옵션 인자를 가지는데, function 을 사용해서 iterable을 하나의 값으로 줄입니다. initializer 는 주어지면 첫 번째 인자로 추가 된다고 생각하면 됩니다.
```
functools.reduce(function, iterable[, initializer])
```

예를 들어 reduce(function, [1,2,3,4,5]) 에서 list 는 [function(1,2),3,4,5] 로 하나의 요소가 줄고, 요소가 하나가 남을 때까지 reduce(function, [function(1,2),3,4,5]) 를 반복합니다.

```py
>>> from functools import reduce

>>> reduce(lambda x,y: x+y, [1,2,3,4,5])
15
```

위에서 map()과 filter() 는 내장 함수이고, reduce() 는 아닙니다.