import math

def add(n):
    s = 0
    i = 1
    while i * i < n:
        if n % i == 0:
            s += i
            s += n / i
        i += 1
    if i * i == n:
        s += i
    s -= n
    return s


sum = [0] * 1000001
for i in range(2, 1000001):
    sum[i] = add(i)

max_length = 0
max_min = 0

for i in range(0, 1000001):
    myset = set()
    flag = True
    start = -1
    j = i
    while True:
        if j <= 1000000 and j not in myset:
            myset.add(j)
            j = sum[j]
        elif j > 1000000:
            flag = False
            break
        else:
            start = j
            break
    if flag:
        length = 1
        min_num = j
        j = sum[j]
        while j != start:
            length += 1
            if j < min_num:
                min_num = j
            j = sum[j]
        if length > max_length:
            max_length = length
            max_min = min_num

print max_min
