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
int cnt[10005];
int main()
{
    int n, a, mmax, ans;
    while (scanf("%d", &n) != EOF)
    {
        memset(cnt, 0, sizeof(cnt));
        mmax = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            cnt[a]++;
        }
        for (int i = 0; i <= 10000; i++)
            if (cnt[i] > mmax)
            {
                mmax = cnt[i];
                ans = i;
            }
        printf("%d\n", ans);
    }
    return 0;
}
