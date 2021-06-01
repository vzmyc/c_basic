# Python3
class A:
    def __init__(self):
        print("A 클래스의 생성자 호출!")

class B(A):
    def __init__(self):
        print("B 클래스의 생성자 호출!")
        super().__init__() # == super(B,self).__init()

class C(A):
    def __init__(self):
        print("C 클래스의 생성자 호출!")
        super().__init__() # == super(C,self).__init()

class D(B, C):
    def __init__(self):
        print("D 클래스의 생성자 호출!")
        super().__init__() # == super(D,self).__init()

objectD = D()


# 어떤 슈퍼클래스를 호출하는가는 self.__class__.__mro__와 'class name'을 이용하여 결정됨.
# 메서드 탐색 순서(Method Resolution Order, MRO)
print(D.__mro__)
