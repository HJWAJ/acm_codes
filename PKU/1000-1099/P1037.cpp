#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;
// dp[n][k][dir] 表示长度为n，首项为k，第二根木棒和第一根之间方向为dir的摆放数
// 求出后，像类似第k个全排列那样一个个位置数出来
// 有点绕。中间数第i位时，这里用的是dp[n-i][k][dir]，但这个i和实际的数字是一个对应关系
const int UP = 0;
const int DOWN = 1;
long long dp[21][21][2];
long long dfs(int n, int k, int dir)
{
    if (dp[n][k][dir] != -1) return dp[n][k][dir];
    if (k > n) return dp[n][k][dir] = 0;
    if (n == 1) return dp[n][k][dir] = 1;
    long long res = 0;
    if (dir == UP)
    {
        for (int i = k; i <= n - 1; i++)
            res += dfs(n - 1, i, dir ^ 1);
    }
    else
    {
        for (int i = 1; i < k; i++)
            res += dfs(n - 1, i, dir ^ 1);
    }
    return dp[n][k][dir] = res;
}
void init()
{
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= i; j++)
        {
            dfs(i, j, UP);
            dfs(i, j, DOWN);
        }
}
void gen(int n, long long k)
{
    long long cnt = 0;
    bool exist[21];
    memset(exist, 0, sizeof(exist));
    int ans[21];
    for (int i = 1; i <= n; i++)
    {
        long long last;
        int j, num = 0;
        for(j = 1; j <= n; j++)
        {
            last = cnt;
            if(!exist[j])
            {
                num++;
                if(i == 1)
                    cnt += dp[n][num][UP] + dp[n][num][DOWN];
                else
                {
                    if(j > ans[i - 1] && (i == 2 || ans[i - 2] > ans[i - 1]))
                        cnt += dp[n - i + 1][num][DOWN];
                    else if(j < ans[i - 1] && (i == 2 || ans[i - 2] < ans[i - 1]))
                        cnt += dp[n - i + 1][num][UP];
                }
                if(cnt >= k)
                    break;
            }
        }
        exist[j] = true;
        ans[i] = j;
        cnt = last;
    }
    printf("%d", ans[1]);
    for (int i = 2; i <= n; i++)
        printf(" %d", ans[i]);
    puts("");
}
int main()
{
    int t, n;
    long long k;
    init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%lld", &n, &k);
        gen(n, k);
    }
    return 0;
}
