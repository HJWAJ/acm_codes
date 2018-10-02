#include <iostream>
#include <cstdio>
using namespace std;
/**
 * 威尔逊定理: (p-1)! = p-1 (mod p)，当且仅当p为素数
 * 所以对每个p>5，只要分别求4次逆元即可。
 */
int prime[20000000];
bool bo[100000001];
int prime_table()
{
    int i, j, flag=0;
    bo[0] = bo[1] = 1;
    for (i = 2; i <= 10000; i++)
        if(!bo[i])
        {
            j = i * i;
            for (; j <= 100000000; j += i) bo[j] = 1;
        }
    for (i = 0; i <= 100000000; i++)
        if(!bo[i]) prime[flag++] = i;
    return flag;
}
long long ext_gcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long tmp = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return tmp;
}
long long inv(long long a, long long mod)
{
    long long x, y;
    ext_gcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}
long long calc(long long p)
{
    long long res = p - 1, tmp = p - 1;
    for (int i = 0; i < 4; i++)
    {
        tmp = tmp * inv(p - i - 1, p) % p;
        res += tmp;
    }
    return res % p;
}
int main()
{
    int flag = prime_table();
    long long sum = (24 + 6 + 2 + 1 + 1) % 5; // (5 - 1)! + (5 - 2)! + ... + (5 - 5)!
    for (int i = 3; i < flag; i++) sum += calc(prime[i]);
    cout << sum << endl;
    return 0;
}
