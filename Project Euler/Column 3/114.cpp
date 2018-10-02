#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;
/**
 * dp[n]表示长度为n的填充的方法数
 * 所以子问题是填充一段黑色和红色之后剩余的长度的方法数。
 * 则dp[n]+=dp[n-i-j-1]，其中i是黑色的长度，j是红色的长度，1是填完红色必须要填1个
 */
long long dp[51];
long long dfs(int n)
{
    if (n < 3) return 1;
    if (dp[n]) return dp[n];
    // 啥也不填
    dp[n] = 1;
    for (int i = 0; i <= n - 3; i++)
        for (int j = 3; i + j <= n; j++)
            dp[n] += dfs(n - i - j - 1);
    return dp[n];
}
int main()
{
    cout << dfs(50) << endl;
    return 0;
}
