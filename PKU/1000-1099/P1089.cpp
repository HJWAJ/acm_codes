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
struct Interval
{
    int start, end;
    bool operator < (const Interval b) const
    {
        return start < b.start;
    }
};
Interval interval[50005], ans[50005];
int ans_cnt;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++) scanf("%d%d", &interval[i].start, &interval[i].end);
        sort(interval, interval + n);
        ans_cnt = 0;
        ans[0] = interval[0];
        for (int i = 1; i < n; i++)
        {
            if (interval[i].start <= ans[ans_cnt].end)
            {
                if (interval[i].end > ans[ans_cnt].end) ans[ans_cnt].end = interval[i].end;
            }
            else
            {
                ans[++ans_cnt] = interval[i];
            }
        }
        for (int i = 0; i <= ans_cnt; i++) printf("%d %d\n", ans[i].start, ans[i].end);
    }
    return 0;
}
