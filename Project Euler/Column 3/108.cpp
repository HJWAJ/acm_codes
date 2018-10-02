#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
// 设x = n + k, y = 1/n - 1/(n+k) = k/n(n+k)
// 所以k整除n^2，且1<=k<=n
// 所以k的个数就是n^2因子的个数/2+1
// 构造合适的n^2，设n=p1^k1 * p2^k2 * ... *pn^kn，n^2的因数个数为(2k1+1)(2k2+1)...(2kn+1)
// 解个数>1000，则n^2因子个数>1999，由于3^7=2187，所以pn<=17, n<7。
// 另外，pi < pi+1, ki >= ki+1。于是枚举所有情况。
// 判断大小时用log。
// 110题3^15 > 8000000，所以pn<=47, n<15
const int MAX = 7;
const long long MAX_NUM = 2000;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int max_exp[] = {1000, 22, 6, 3, 2, 2, 1};
void print(int exp[], int n)
{
    for (int i = 0; i < n; i++)
        cout << exp[i] << ' ';
    cout << endl;
}
int calc_factor(int exp[])
{
    long long res = 1;
    for (int i = 0; ; i++)
    {
        res *= (exp[i] * 2 + 1);
        if (res >= MAX_NUM)
        {
            return i + 1;
        }
    }
}
double calc(int exp[], int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
        res += exp[i] * log(prime[i] * 1.0);
    return res;
}
long long calc_ans(int exp[], int n)
{
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < exp[i]; j++)
        {
            res *= prime[i];
        }
    }
    return res;
}
void update(int exp[], int n, int min_exp[])
{
    for (int i = 0; i < n; i++)
        min_exp[i] = exp[i];
}
void dfs(int exp[], int n, int i, int min_exp[], int &min_n, double &min_num)
{
    int tmp_n;
    double tmp;
    if (i == n)
    {
        tmp_n = calc_factor(exp);
        tmp = calc(exp, tmp_n);
        if (tmp < min_num)
        {
            min_n = tmp_n;
            min_num = tmp;
            update(exp, min_n, min_exp);
        }
        return;
    }
    else if (i == 0)
    {
        for (int j = 1; j <= max_exp[i]; j++)
        {
            exp[i] = j;
            dfs(exp, n, i + 1, min_exp, min_n, min_num);
        }
    }
    for (int j = 1; j <= max_exp[i] && j <= exp[i - 1]; j++)
    {
        exp[i] = j;
        dfs(exp, n, i + 1, min_exp, min_n, min_num);
    }
}
int main()
{
    int exp[MAX], min_exp[MAX], min_n;
    double min_num = 1.0;
    for (int i = 0 ; i < MAX; i++)
    {
        exp[i] = 1;
        min_exp[i] = 1;
        min_num += log(prime[i] * 1.0);
    }
    min_n = MAX;
    dfs(exp, MAX, 0, min_exp, min_n, min_num);
    cout << calc_ans(min_exp, min_n) << endl;
    return 0;
}
