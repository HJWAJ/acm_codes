#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
long long dp[1005][6];
const long long mod = 1000000007;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][3] = (dp[i - 1][1] + dp[i - 1][3] * 2) % mod;
            dp[i][4] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] * 2) % mod;
            dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5] * 2) % mod;
        }
        printf("%lld\n", dp[n][5]);
    }
    return 0;
}
