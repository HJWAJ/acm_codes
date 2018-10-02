#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;
/**
 * ������д��f(n, m)�Ľⷨ
 */
long long dp[510][51];
long long dfs(int n, int m)
{
    if (n < m) return 1;
    if (dp[n][m]) return dp[n][m];
    // ɶҲ����
    dp[n][m] = 1;
    for (int i = 0; i <= n - m; i++)
        for (int j = m; i + j <= n; j++)
            dp[n][m] += dfs(n - i - j - 1, m);
    return dp[n][m];
}
int main()
{
    int i = 0;
    while (dfs(i, 50) < 1000000) i++;
    cout << i << endl;
    return 0;
}
