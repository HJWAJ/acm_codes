#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
const __int64 INF = 0x5555555555555555LL;
struct Node
{
    int pos, id;
} team[4005], shelter[4005];
__int64 dp[2][4005];
bool pre[4005][4005];
int ans[4005];
bool cmp(Node a, Node b)
{
    return a.pos < b.pos;
}
__int64 dis(int i, int j)
{
    return abs(team[i].pos - shelter[j].pos);
}
int main()
{
    int n, m;
    while (scanf("%d", &n) != EOF)
    {
        memset(pre, 0, sizeof(pre));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &team[i].pos);
            team[i].id = i;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &shelter[i].pos);
            shelter[i].id = i;
        }
        sort(team, team + n, cmp);
        sort(shelter, shelter + m, cmp);
        memset(dp, 5, sizeof(dp));
        dp[0][0] = dis(0, 0);
        pre[0][0] = 1;
        for (int i = 1; i < n; i++)
        {
            int pos = (i & 1);
            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                {
                    dp[pos][j] = dp[pos ^ 1][j] + dis(i, j);
                    pre[i][j] = 1;
                }
                else
                {
                    dp[pos][j] = dp[pos ^ 1][j] + dis(i, j);
                    pre[i][j] = 1;
                    if (dp[pos][j] > dp[pos ^ 1][j - 1] + dis(i, j))
                    {
                        dp[pos][j] = dp[pos ^ 1][j - 1] + dis(i, j);
                        pre[i][j] = 0;
                    }
                }
                if (dp[pos][j] > INF) dp[pos][j] = INF;
            }
        }
        ans[team[n - 1].id] = shelter[m - 1].id;
        int tmp = pre[n - 1][m - 1] ? m - 1 : m - 2;
        for(int i = n - 2; i >= 0; i--)
        {
            ans[team[i].id] = shelter[tmp].id;
            tmp = pre[i][tmp] ? tmp : tmp - 1;
        }
        printf("%I64d\n", dp[(n - 1) & 1][m - 1]);
        for (int i = 0; i < n - 1; i++) printf("%d ", ans[i] + 1);
        printf("%d\n", ans[n - 1] + 1);
    }
    return 0;
}
