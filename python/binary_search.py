def binary_search_recursion(target, start, end, data):
    if start > end:
        return None

    mid = (start + end) // 2

    if data[mid] == target:
        return mid
    elif data[mid] > target:
        end = mid - 1
    else:
        start = mid + 1        

    return binary_search_recursion(target, start, end, data)

if __name__ == '__main__':
    li = [i*3 for i in range(11)]
    target = 6
    idx = binary_search_recursion(target, 0, 10, li)

    print('target:', target)
    print(li)
    print('index:',idx)
