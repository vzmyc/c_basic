def insert(v):
    for i in range(1, len(v)):
        j = i-1
        while(j>=0 and v[i]<v[j]):
            j -= 1
        v.insert((j+1), v[i])
        del v[i+1]
    return v

print(insert([7,6,1,8,5,3,9,4]))
