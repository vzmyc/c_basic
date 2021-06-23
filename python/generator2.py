#Generator 예제2

#list comprehension 사용 리스트 생성
my_nums3 = [x for x in [1, 2, 3, 4, 5]]

#타입 확인
print (type(my_nums3))
#for문 사용 출력
for i in my_nums3:
    print (i)


#List comprehension 사용 제네레이터 생성
my_nums4 = (x for x in [1, 2, 3, 4, 5])
#my_nums4 = [x for x in [1, 2, 3, 4, 5]] #리스트 생성


#타입 확인
print (type(my_nums4))
#리스트 변환 출력
#print(list(my_nums4))

#제네레이터 출력
print (next(my_nums4))
print (next(my_nums4))
print (next(my_nums4))
print (next(my_nums4))
print (next(my_nums4))
#print (next(my_nums4)) #주석 해제 시 StopIteration 예외 발생
