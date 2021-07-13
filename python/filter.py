# filter 적용 안했을 때
target = [ 1,2,3,4,5,6,7 ]
new=[]

def is_even(num: int) -> bool:
  if num%2 ==0 :
    return True
  else :
    return False

for i in target :
  if is_even(i):
    new.append(i)
  
print(new)

# filter 적용 했을 때
target=[1,2,3,4,5,6]
a= filter(lambda x: x%2==0, target)
print(a)
print(list(a))
#print(list(a[2])) 이건 안됨..

b=list(filter(lambda x: x%2==0, target))
print(b)
print(b[2])


