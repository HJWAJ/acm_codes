#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;
int a[105], c[105];
bool dp[100005];
int main()
{
    int n, m, k, mm, cnt;
    while (scanf("%d%d", &n, &m) && (n || m))
    {
        cnt = 0;
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < n; i++) scanf("%d", c + i);
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for (int i = 0;i < n; i++)
        {
            if(c[i] * a[i] >= m)
            {
                for(int j = a[i]; j <= m; j++)
                    dp[j] |= dp[j - a[i]];
            }
            else
            {
                k = 1;
                mm = c[i];
                while (k < mm)
                {
                    for (int j = m; j >= k * a[i]; j--)
                        dp[j] |= dp[j - k * a[i]];
                    mm -= k;
                    k <<= 1;
                }
                for (int j = m; j >= mm * a[i]; j--)
                    dp[j] |= dp[j - mm * a[i]];
            }
        }
        for (int i = 1; i <= m; i++)
            if (dp[i])
                cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
