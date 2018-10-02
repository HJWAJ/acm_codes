#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

/**
 * 先求出后9位包含1~9的（只需要模除10^9）
 * 再对这些分别验证前9位
 * 验证方式：
 * fn = (1.0/ sqrt(5)) * (((1 + sqrt(5))/2) ^ n - ((1 - sqrt(5))/2) ^ n) 在n足够大的时候后半部分是无穷小量
 * lg fn = nlg((1 + sqrt(5))/2) - lg sqrt(5)
 * 对整数a = c1 * 10^c2，lg a = c2（整数部分） + lg c1（小数部分）
 * 所以只要求lg fn的小数部分，设为c，然后10^c的整数部分就是最高位
 * 10^c * 10^8的整数部分就是前9位
 */
const int MOD = 1000000000;
bool ok_last(int n)
{
    char s[10];
    sprintf(s, "%d", n);
    sort(s, s + 9);
    for (int i = 0; i < 9; i++)
        if (s[i] - '0' != i + 1)
            return false;
    return true;
}
bool ok_prev(int n)
{
    double lgf = n * log10((1 + sqrt(5.0)) / 2) - log10(sqrt(5.0));
    int ilgf = lgf;
    double flgf = lgf - ilgf;
    int num = floor(pow(10, flgf) * 100000000 + 0.5);
    return ok_last(num);
}
int main()
{
    int i = 3, a = 1, b = 1, c;
    while(1)
    {
        c = (a + b) % MOD;
        if (ok_last(c) && ok_prev(i))
        {
            cout << i << endl;
            break;
        }
        a = b;
        b = c;
        i++;
    }
	return 0;
}
