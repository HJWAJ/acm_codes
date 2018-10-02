import math

# Helen formula to find (3*a+1, a-1) or (3*a-1, a+1)

def check(a, b):
    if a == 0 or b == 0:
        return False
    num = math.sqrt(a * b)
    num = int(round(num))
    if num * num != a * b:
        return False
    return True

a = 3
sum = 0
while a * 3 + 1 <= 1000000000:
    if check(3 * a + 1, a - 1):
        sum += a * 3 + 1
    if check(3 * a - 1, a + 1):
        sum += a * 3 - 1
    a += 2
print sum