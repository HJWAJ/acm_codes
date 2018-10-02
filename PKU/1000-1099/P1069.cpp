#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
bool g[80][80][2];
int a[15];
int n, len;
bool flag;
void print_g()
{
    for (int i = len * 2 - 1; i >= 0; i--)
    {
        for (int j = 0; j < len * 2; j++) printf("(%d,%d) ", g[i][j][0] ? 1 : 0, g[i][j][1] ? 1 : 0);
        puts("");
    }
    puts("");
}
void init_g()
{
    memset(g, 0, sizeof(g));
    // see as parallelogram, left-bottom and right-top corner set true
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
            g[i][j][0] = g[i][j][1] = true;
        g[i][len - i - 1][0] = true;
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
            g[len + i][len * 2 - i + j][0] = g[len + i][len * 2 - i + j][1] = true;
        g[len + i][len * 2 - 1 - i][1] = true;
    }
}
void pre_deal()
{
    sort(a, a + n);
    while (a[n - 1] > len) n--;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[j] % a[i] == 0)
            {
                for (int k = j + 1; k < n; k++)
                    a[k - 1] = a[k];
                n--;
                j--;
            }
    }
}
int get_max_fill_size(int row, int col, int dir)
{
    int res = 0;
    if (dir == 0)
    {
        while (col + res < 2 * len && row + res < 2 * len && !g[row][col + res][0]) res++;
    }
    else
    {
        int res1 = 0, res2 = 0;
        while (col - res1 >= 0 && row + res1 < 2 * len && !g[row + res1][col - res1][1]) res1++;
        while (row + res2 < 2 * len && !g[row + res2][col][1]) res2++;
        res = min(res1, res2);
    }
    return res;
}
void fill_tri(int row, int col, int dir, int size, int value)
{
    if (dir == 0)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
                g[row + i][col + j][0] = g[row + i][col + j][1] = value;
            g[row + i][col + size - 1 - i][0] = value;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < i; j++)
                g[row + i][col - i + j + 1][0] = g[row + i][col - i + j + 1][1] = value;
            g[row + i][col - i][1] = value;
        }
    }
    //print_g();
}
void fill_tri(int row, int col, int dir, int size)
{
    fill_tri(row, col, dir, size, true);
}
void revert_tri(int row, int col, int dir, int size)
{
    fill_tri(row, col, dir, size, false);
}
// dir -> up 0, down 1
bool dfs(int row, int col, int dir)
{
    if (row >= len * 2) return true;
    if (col >= len * 2) return dfs(row + 1, 0, 0);
    if (dir == 0 && g[row][col][dir]) return dfs(row, col, 1);
    if (dir == 1 && g[row][col][dir]) return dfs(row, col + 1, 0);
    int max_fill_size = get_max_fill_size(row, col, dir);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max_fill_size)
            break;
        fill_tri(row, col, dir, a[i]);
        if (dfs(row, col, dir)) return true;
        revert_tri(row, col, dir, a[i]);
    }
    return false;
}
void test_pre()
{
    len = 10;
    int i = 0;
    while(~scanf("%d", a + i)) i++;
    n = i;
    pre_deal();
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    puts("");
    exit(0);
}
void test_init_g()
{
    len = 3;
    init_g();
    print_g();
    exit(0);
}
void test_fill()
{
    len = 2;
    init_g();
    fill_tri(0, 1, 1, 2);
    fill_tri(0, 2, 0, 2);
    fill_tri(0, 3, 1, 2);
    fill_tri(2, 0, 0, 2);
    fill_tri(2, 2, 0, 2);
    fill_tri(2, 1, 1, 2);
    print_g();
    exit(0);
}
int main()
{
    //freopen("1.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        flag = false;
        scanf("%d%d", &len, &n);
        init_g();
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        pre_deal();
        for (int i = 0; i < n; i++)
            if (len % a[i] == 0)
                flag = true;
        if (flag)
        {
            puts("YES");
            continue;
        }
        if (dfs(0, 0, 0)) puts("YES");
        else puts("NO");
    }
    return 0;
}
