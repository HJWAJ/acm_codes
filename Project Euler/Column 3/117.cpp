#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
long long dp[51];
long long dfs(int n)
{
    if (n < 0) return 0;
    if (dp[n]) return dp[n];
    dp[n] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 2; j <= 4; j++)
            dp[n] += dfs(n - i - j);
    return dp[n];
}
int main()
{
    cout << dfs(50) << endl;
    return 0;
}
