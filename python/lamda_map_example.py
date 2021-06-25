import time
from functools import reduce

#시작시간
start_time = time.time()


if __name__ == '__main__':

    testArr = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

    #filter : 특정 조건에 부합하는 요소만 True로 간주
    #reduce : 첫 번째 인덱스의 요소부터 순차적으로 정의된 함수로 처리

    #filter + lambda 예제
    outArr1 = list(filter(lambda x: x > 5 and x < 15, testArr))
    print('Lambda Filter Example1 : ', outArr1)

    #reduce + lambda 예제
    outArr2 = reduce(lambda x, y: x + y, testArr)
    print('Lambda Reduce Example2 : ', outArr2)


#종료시간
print("--- %s seconds ---" % (time.time() - start_time))
