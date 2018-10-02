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
// dilworth theory
const int MAXN = 5005;
struct node
{
    int len;
    int wei;
    bool operator < (const node b) const
    {
        if (len != b.len) return len < b.len;
        return wei < b.wei;
    }
} per[MAXN];
int dp[MAXN];
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d%d", &per[i].len, &per[i].wei);
        sort(per, per + n);
        for (int i = 0; i < n;i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
                if (per[j].wei > per[i].wei && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
        }
        int mmax = 0;
        for (int i = 0; i < n; i++)
            mmax = max(mmax,dp[i]);
        printf("%d\n", mmax);
    }
    return 0;
}
