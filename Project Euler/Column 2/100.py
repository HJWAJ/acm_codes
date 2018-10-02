# a / b * (a-1) / (b-1) == 1/2
# a = (1 + sqrt(1 + 2*(b^2 - b))) / 2, b >= 10**12
# a_min = 707106781187
# a(n)=6*a(n-1)-a(n-2)-2 (from OEIS A011900)
# 2(2a-1)^2 - (2b-1)^2 = 1
# let 2a-1 = x, 2b-1 = y
# 2x^2 - y^2 = 1

a_min = 707106781187L
a = 15
b = 85
while b < a_min:
    c = 6 * b - a - 2
    a = b
    b = c
print b
