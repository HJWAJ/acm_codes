#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
/**
 * repunit 表示由全1组成的数。
 * 显然任何数n用n-1进制均可表示为11。
 * 于是转化为求所有的n，n可用非n-1进制表示为全1组成的数。
 * 于是对于进位制b，构造b^2+b+1,b^3+b^2+b+1...并去重，最后求和。
 */

const long long N = 1000000000000LL;
set<long long> s;
int main()
{
    long long sum = 0, tmp;
    for (long long i = 2; ; i++)
    {
        tmp = i * i + i + 1;
        if (tmp > N) break;
        while (tmp <= N)
        {
            s.insert(tmp);
            tmp *= i;
            tmp++;
        }
    }
    for (set<long long>::iterator it = s.begin(); it != s.end(); ++it) sum += *it;
    cout << sum + 1 << endl;
    return 0;
}
