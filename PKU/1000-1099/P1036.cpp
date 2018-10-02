#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct Gangster
{
    int t, p, s;
} g[105];
bool cmp(Gangster &a, Gangster &b)
{
    return a.t < b.t;
}
int dp[105][105];
int dfs(int n, int k)
{
    if (dp[n][k] != -1) return dp[n][k];
    if (n == 0) return dp[n][k] = 0;
    if (k > g[n].t) return dp[n][k] = 0;
    int res = 0;
    for (int i = 0; i <= 100; i++)
        if (abs(g[n].t - g[n - 1].t) >= abs(k - i))
        {
            int tmp = dfs(n - 1, i);
            if (tmp > res) res = tmp;
        }
    if (k == g[n].s) return dp[n][k] = res + g[n].p;
    else return dp[n][k] = res;
}
int main()
{
    int n, k, t, ans;
    while (scanf("%d%d%d", &n, &k, &t) != EOF)
    {
        g[0].t = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &g[i].t);
        for (int i = 1; i <= n; i++) scanf("%d", &g[i].p);
        for (int i = 1; i <= n; i++) scanf("%d", &g[i].s);
        sort(g + 1, g + n + 1, cmp);
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= 100; i++) dfs(n, i);
        ans = -1;
        for (int i = 0; i <= 100; i++)
            if (dp[n][i] > ans)
                ans = dp[n][i];
        printf("%d\n", ans);
    }
    return 0;
}
