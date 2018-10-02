#coding=utf-8

# 记忆化搜索，因为都是除2递降，有很多重复值
f_dict = {}

def f(n):
    if n == 1:
        return 1
    elif n in f_dict:
        pass
    elif n % 2 == 1:
        # 如果是奇数，那只能有一个1，剩下的是个偶数，最小是2，相当于这个偶数除2之后最小是1
        f_dict[n] = f((n - 1) / 2)
    else:
        # 如果是偶数，有两种情况：
        # 1. 含有1，那么相当于n-1这个奇数的情况下再加1。
        # 2. 不含有1，那么最小是2，同上。
        f_dict[n] = f(n - 1) + f(n / 2)
    return f_dict[n]

print f(10 ** 25)
