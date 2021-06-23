#Generator 예제1

#리스트 생성
def square_numbers1(nums):
    result = []
    for i in nums:
        result.append(i * i)
    return result

my_nums1 = square_numbers1([1, 2, 3, 4, 5])

#타입 확인
print(type(my_nums1))
#리스트 출력
print(my_nums1)
#합계
print(sum(my_nums1))


#제네레이터 생성
def square_numbers2(nums):
    for i in nums:
        yield i * i

my_nums2 = square_numbers2([1, 2, 3, 4, 5])

#타입 확인
print(type(my_nums2))
#제네레이터 출력
print (my_nums2)
#합계
#print(sum(my_nums2))

print (next(my_nums2))
print (next(my_nums2))
print (next(my_nums2))
print (next(my_nums2))
print (next(my_nums2))
#print (next(my_nums2)) #주석 해제 시 StopIteration 예외 발생
