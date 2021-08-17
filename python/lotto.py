import random

print("lotto number machine")
print("---------------------")

num = input("how many games?:")
print("---------------------")

for  i in range(0, int(num)):
    lotto = random.sample(range(1, 46), 6)
    lotto.sort()
    print(lotto)
print("---------------------")
