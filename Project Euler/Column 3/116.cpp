#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
long long dp[510][51];
long long dfs(int n, int m)
{
    if (n < m) return 1;
    if (dp[n][m]) return dp[n][m];
    dp[n][m] = 1;
    for (int i = 0; i <= n - m; i++)
            dp[n][m] += dfs(n - i - m, m);
    return dp[n][m];
}
int main()
{
    cout << dfs(50, 2) + dfs(50, 3) + dfs(50, 4) - 3 << endl;
    return 0;
}
