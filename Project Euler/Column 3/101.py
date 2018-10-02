def func(n):
    sum = 0
    for i in range(0, 11):
        sum += (-n) ** i
    return sum

ops = [func(n) for n in range(1, 11)]

def calc(coef, n):
    sum = 0
    for i in range(0, len(coef)):
        sum += coef[i] * (n ** i)
    return sum

def bop(n):
    coefs = [[i**j for j in range(0, n)] for i in range(1, n + 1)]
    for i in range(0, n):
        coefs[i].append(ops[i])
    for k in range(0, n - 1):
        for i in range(k + 1, n):
            coefs[i][k] = coefs[i][k] / coefs[k][k]
        for i in range(k + 1, n):
            for j in range(k + 1, n + 1):
                coefs[i][j] = coefs[i][j] - coefs[i][k] * coefs[k][j]
    for i in range(n-1, -1, -1):
        sum = 0
        for j in range(i + 1, n):
            sum += coefs[i][j] * coefs[j][n]
        coefs[i][n] = (coefs[i][n] - sum) / coefs[i][i]
    cur_coef = [coefs[i][n] for i in range(0, n)]
    return calc(cur_coef, n + 1)

s = 0
for i in range(1, 11):
    s += bop(i)
print s