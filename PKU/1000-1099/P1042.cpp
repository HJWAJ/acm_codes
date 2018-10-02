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
struct Solve
{
    int lake_num;
    int time[25];
    int total;
    bool operator < (const Solve b) const
    {
        if (total != b.total) return total < b.total;
        for (int i = 0; i < lake_num; i++)
            if (time[i] != b.time[i])
                return time[i] < b.time[i];
        return false;
    }
};
struct Lake
{
    int current;
    int d;
    void decrease()
    {
        current -= d;
        if (current < 0) current = 0;
    }
};
int l[25], d[25], dis[25];
Lake lake[25];
Solve init_solve()
{
    Solve solve;
    solve.total = -1;
    return solve;
}
Lake init_lake(int n)
{
    Lake lake;
    lake.current = l[n];
    lake.d = d[n];
    return lake;
}
void print(int n, Solve solve)
{
    for (int i = 0; i < n; i++) printf("Lake %d: %d\n", i, lake[i].current);
    printf("Solve time:");
    for (int i = 0; i < n; i++) printf(" %d", solve.time[i]);
    printf("\nSolve: %d\nSolve lake_num: %d\n", solve.total, solve.lake_num);
}
Solve current_solve(int n, int t)
{
    Solve solve;
    solve.lake_num = n;
    solve.total = 0;
    for (int i = 0; i < n; i++) solve.time[i] = 0;
    for (int i = 0; i < n; i++)
        lake[i] = init_lake(i);

    while (t > 0)
    {
        //getchar();
        //print(n, solve);
        t--;
        int max_val = -1;
        int cur_lake;
        for (int i = 0; i < n; i++)
            if (lake[i].current > max_val)
            {
                max_val = lake[i].current;
                cur_lake = i;
            }
        solve.total += lake[cur_lake].current;
        //if (lake[cur_lake].current > 0)
        solve.time[cur_lake]++;
        lake[cur_lake].decrease();
    }
    return solve;
}
int main()
{
    int n, t;
    while (scanf("%d", &n) && n)
    {
        scanf("%d", &t);
        t *= 12;
        for (int i = 0; i < n; i++) scanf("%d", l + i);
        for (int i = 0; i < n; i++) scanf("%d", d + i);
        dis[0] = 0;
        for (int i = 1; i < n; i++)
        {
            scanf("%d", dis + i);
            dis[i] += dis[i - 1];
        }
        Solve best = init_solve();
        for (int i = 0; i < n; i++)
        {
            Solve solve = current_solve(i + 1, t - dis[i]);
            if (best < solve) best = solve;
        }
        //printf("%d\n", best.lake_num);
        //getchar();
        for (int i = 0; i < best.lake_num - 1; i++) printf("%d, ", best.time[i] * 5);
        printf("%d", best.time[best.lake_num - 1] * 5);
        for (int i = best.lake_num; i < n; i++) printf(", 0");
        puts("");
        printf("Number of fish expected: %d\n\n", best.total);
    }
    return 0;
}
