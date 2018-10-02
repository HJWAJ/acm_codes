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
long long a[10005];
bool check(long long len, int n, int k)
{
    long long cnt = 0;
    for (int i = 0; i < n; i++) cnt += a[i] / len;
    return cnt >= k;
}
int main()
{
    int n, k;
    long long sum, l, r, mid;
    double tmp;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &tmp);
            a[i] = (tmp + 0.005) * 100LL;
            sum += a[i];
        }
        if (!check(1, n, k)) puts("0.00");
        else
        {
            l = 1;
            r = sum + 1;
            while (r - l > 1)
            {
                mid = (l + r) / 2;
                if (check(mid, n, k)) l = mid;
                else r = mid;
            }
            printf("%.2lf\n", l / 100.0);
        }
    }
    return 0;
}
