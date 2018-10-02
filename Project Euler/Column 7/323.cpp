#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
/**
 * dp[i]表示填满i位的期望。
 * 当前状态对一个新的数取或时，会有一定概率转化到当前状态、比当前多个1的状态、。。。一直到满状态。因此：
 * dp[32] = (dp[32] + 1) * (c(32, 32) / 2^32) + (dp[31] + 1) * (c(32, 31) / 2^32) + ... + (dp[1] + 1) * (c(32, 1) / 2^32) + 1 * (c(32, 0) / 2^32)
 * 。。。
 * dp[1] = (c(1, 1) / 2) * (dp[1] + 1) + (c(1, 0) / 2) * 1
 * 这样相当于列出线性方程组，解方程即可。
 */
long double dp[33];
long long c[33][33];
void init()
{
    for (int i = 0; i <= 32; i++)
        for (int j = 0; j <= 32; j++)
        {
            if (j == 0) c[i][j] = 1;
            else if (j > i) c[i][j] = 0;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
}
int main()
{
    init();
    dp[0] = 0;
    for (int i = 1; i <= 32; i++)
    {
        dp[i] = 1.0;
        for (int j = 0; j < i; j++) dp[i] += c[i][j] * (dp[j] + 1.0);
        dp[i] /= (1LL << i) - 1.0;
    }
    printf("%.10lf\n", (double)dp[32]);
    return 0;
}
