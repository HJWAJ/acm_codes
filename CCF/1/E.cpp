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
char g[55][55];
bool g1[55][55], g2[55][55];
void print(bool gg[55][55])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) printf("%d", gg[i][j] ? 1 : 0);
        puts("");
    }
}
void dfs1(int x, int y, int n, int m)
{
    if (x < 0 || x >= n) return;
    if (y < 0 || y >= m) return;
    if (g1[x][y] || g[x][y] == '#') return;
    g1[x][y] = true;
    if (g[x][y] == '+')
    {
        dfs1(x - 1, y, n, m);
        dfs1(x, y - 1, n, m);
        dfs1(x + 1, y, n, m);
        dfs1(x, y + 1, n, m);
    }
    if (g[x][y] == '-')
    {
        dfs1(x, y - 1, n, m);
        dfs1(x, y + 1, n, m);
    }
    if (g[x][y] == '|')
    {
        dfs1(x - 1, y, n, m);
        dfs1(x + 1, y, n, m);
    }
    if (g[x][y] == '.')
    {
        dfs1(x + 1, y, n, m);
    }
}
void dfs2(int x, int y, int n, int m)
{
    //cout << x << ' ' << y << endl;
    if (x < 0 || x >= n) return;
    if (y < 0 || y >= m) return;
    if (g2[x][y]) return;
    g2[x][y] = 1;
    //print(g2);
    if (g[x][y - 1] == '-' || g[x][y - 1] == '+') dfs2(x, y - 1, n, m);
    if (g[x][y + 1] == '-' || g[x][y + 1] == '+') dfs2(x, y + 1, n, m);
    if (g[x - 1][y] == '|' || g[x - 1][y] == '+' || g[x - 1][y] == '.') dfs2(x - 1, y, n, m);
    if (g[x + 1][y] == '|' || g[x + 1][y] == '+') dfs2(x + 1, y, n, m);
}
int main()
{
    int n, m, sx, sy, tx, ty, cnt;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        cnt = 0;
        memset(g1, 0, sizeof(g1));
        memset(g2, 0, sizeof(g2));
        for (int i = 0; i < n; i++) scanf("%s", g[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                    g[i][j] = '+';
                }
                if (g[i][j] == 'T')
                {
                    tx = i;
                    ty = j;
                    g[i][j] = '+';
                }
            }
        dfs1(sx, sy, n, m);
        dfs2(tx, ty, n, m);
        //puts("");
        //print(g1);
        //puts("");
        //print(g2);
        //puts("");
        if (!g1[tx][ty]) puts("I'm stuck!");
        else
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (g1[i][j] && !g2[i][j])
                        cnt++;
            printf("%d\n", cnt);
        }
    }
    return 0;
}
