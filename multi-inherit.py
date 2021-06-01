# Python3
class A:
    def __init__(self):
        print("A 클래스의 생성자 호출!")

class B(A):
    def __init__(self):
        print("B 클래스의 생성자 호출!")
        A.__init__(self)

class C(A):
    def __init__(self):
        print("C 클래스의 생성자 호출!")
        A.__init__(self)

class D(B, C):
    def __init__(self):
        print("D 클래스의 생성자 호출!")
        B.__init__(self)
        C.__init__(self)

objectD = D()
