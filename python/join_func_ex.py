print('ex1>')
a = ['a', 'b', 'c', 'd', '1', '2', '3']
print(a)
print()
 
# 리스트를 문자열로 : join 이용
result1 = "".join(a)
print(result1)
 
 
# 리스트를 문자열로 : 하나하나 문자열을 더해서.
result2 = ''
for v in a:
    result2 += v
 
print(result2)


print('\nex2>')
# 원본 리스트
a = ['BlockDMask', 'python', 'join', 'example']
print(a)
print()
 
# 리스트를 문자열로 합치기
result1 = "_".join(a)
print(result1)
 
# 리스트를 문자열로 합치기
result2 = ".".join(a)
print(result2)


print('\nex3>')
# 원본 리스트
a = ['BlockDMask', 'python', 'example', 'happy new year']
print(a)
print()

# 리스트를 문자열로 합치기
result = ".\n".join(a)

print(result)

