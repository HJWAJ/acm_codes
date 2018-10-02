// 题意：
// 5是最小的n使得n!能被10整除，所以s(10)=5
// 10是最小的n使得n!能被25整除，所以s(25)=10
// 求s(1)+..+s(10^8)

// 题解：
// 根据素数来筛出s(n)
// 例如n=2^3*3^2，则
// 对于2，需要阶乘为4，s(n)暂记为4；
// 对于3，需要阶乘为9，s(n)最终记为9。

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int SIZE = 100000000;
// 打素数表
int prime[20000000];
bool bo[SIZE + 1];
int prime_count;
long long s[SIZE + 1];
int prime_table()
{
    int i, j, flag=0;
    memset(bo, 0, sizeof(bo));
    bo[0] = bo[1] = 1;
    for (i = 2; i <= 10000; i++)
        if(!bo[i])
        {
            j = i * i;
            for (; j <= SIZE; j += i) bo[j] = 1;
        }
    for (i = 0; i <= SIZE; i++)
        if(!bo[i]) prime[flag++] = i;
    return flag; // 返回素数个数
}

// 筛选只有一个素因子的s
void s_exp()
{
    s[1] = 1;
    for (int i = 0; i < prime_count; i++)
    {
        int p = prime[i];
        int base = p;
        long long cur = p;
        int exp = 1;
        do
        {
            if (exp == 0)
            {
                base += p;
                int temp = base; // 计算base中有几个p
                while (temp % p == 0)
                {
                    temp /= p;
                    exp++;
                }
            }
            s[cur] = base;
            cur *= p;
            exp--;
        } while (cur < SIZE);
    }
}

long long ans[105],ansp[105],flag;//ans数组记录分解质因数的结果，flag记录质因数的个数，******相同的质因数不合并！
long long pri[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
long long gcd(long long a, long long b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
long long multi(long long a, long long b, long long n)
{
    long long tmp = 0;
    b = (b % n + n) % n;
    while(b)
    {
        if(b & 1)
        {
            tmp += a;
            if(tmp >= n)
                tmp -= n;
        }
        a <<= 1;
        if(a >= n)a -= n;
        b >>= 1;
    }
    return tmp;
}
long long multimod(long long a, long long m, long long n)
{
    long long tmp=1;
    a %= n;
    while(m)
    {
        if(m & 1) tmp = multi(tmp, a, n);
        a = multi(a, a, n);
        m >>= 1;
    }
    return tmp;
}
bool miller_rabin(long long n)
{
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    if(!(n & 1))
        return false;
    long long k = 0, i, j, m, a;
    m = n - 1;
    while(!(m & 1)) m >>= 1, k++;
    for(i = 0; i < 10; i++)
    {
        if(pri[i] >= n)
            return true;
        a = multimod(pri[i], m, n);
        if(a == 1) continue;
        for(j = 0; j < k; j++)
        {
            if(a == n - 1)
                break;
            a = multi(a, a, n);
        }
        if(j == k)
            return false;
    }
    return true;
}
long long pollard_rho(long long c, long long n)//寻找因数
{
    long long i,x,y,k,d;
    i=1;
    x=y=rand()%n;
    k=2;
    do{
        i++;
        d=gcd(n+y-x,n);
        if(d>1&&d<n)
            return d;
        if(i==k) y=x,k<<=1;
        x=(multi(x,x,n)+n-c)%n;
    }while(y!=x);
    return n;
}
void rho(long long n)//递归分解
{
    if(!bo[n])
    {
        ans[flag]=n;
        flag++;
        return;
    }
    long long t=n;
    while(t>=n)
        t=pollard_rho(rand()%(n-1)+1,n);//这一步的作用是随机取出一个因数，不一定是素数，也不确定大小
    rho(t);
    rho(n/t);
    return;
}

int npow(int base, int exp)
{
    return (int) multimod(base, exp, SIZE + 1);
}

int main()
{
    prime_count = prime_table();
    puts("prime table generated");
    s_exp();
    puts("s table generated");
    long long sum = 0;
    for (int i = 2; i <= SIZE; i++)
    {
        if (s[i])
        {
            sum += s[i];
        }
        else
        {
            flag=0;
            rho(i);
            sort(ans,ans+flag);
            ansp[0] = ans[0];
            ansp[1] = 1;
            int flag2 = 0;
            for (int j = 1; j < flag; j++)
            {
                if (ans[j] == ansp[flag2 << 1]) ansp[(flag2 << 1) + 1]++;
                else
                {
                    flag2++;
                    ansp[flag2 << 1] = ans[j];
                    ansp[(flag2 << 1) + 1] = 1;
                }
            }
            flag2++;
            for (int j = 0; j < flag2; j++)
            {
                int ppow = npow(ansp[j << 1], ansp[(j << 1) + 1]);
                if (s[i] < s[ppow]) s[i] = s[ppow];
            }
            sum += s[i];
        }
    }
    printf("%lld\n", sum);
    return 0;
}

// 35 minutes, 43 seconds, slow
// Answer:476001479068717
