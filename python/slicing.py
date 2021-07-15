# obj[start :] : 특정 시작 위치 부터 끝까지 가져오기
obj =['g', 'i', 'l', 'l', 'o', 'g']

print(obj[3:])
print(obj[-3:])

# ['l', 'o', 'g']
# ['l', 'o', 'g']


# obj[: end] : 시작부터 특정 종료 위치까지 가져오기
obj =['g', 'i', 'l', 'l', 'o', 'g']

print(obj[:3])
print(obj[:-3])

# ['g', 'i', 'l']
# ['g', 'i', 'l']

# obj[start : end] : 특정 시작 위치부터 특정 종료 위치까지 가져오기
obj =['g', 'i', 'l', 'l', 'o', 'g']

print(obj[2:4])
print(obj[-4:-2])

# ['l', 'l']
# ['l', 'l']


# obj[:: step] : step만큼 이동하면서 가져오기
obj =['g', 'i', 'l', 'l', 'o', 'g']

# step 양수인 경우
print(obj[::2])
# ['g', 'l', 'o']

# end는 포함되지 않아 `g`는 포함되지 않음
print(obj[1:5:2])
# ['i', 'l']

# step 음수인 경우
print(obj[::-1])
# ['g', 'o', 'l', 'l', 'i', 'g']

print(obj[4::-2])
# ['o', 'l', 'g']