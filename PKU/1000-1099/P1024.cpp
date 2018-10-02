#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <set>
using namespace std;
int x1[10005], y1[10005], x2[10005], y2[10005];
int g[105][105], g1[105][105], g2[105][105];
bool vis[105][105];
char s[10005];
int len;
set<pair<int, int> > myset;
int endx, endy, r, c;
// left -> 1  top -> 2  right -> 4  bottom -> 8
void init_g()
{
    memset(g, 0, sizeof(g));
    for (int i = 0; i < r; i++)
    {
        g[i][0] |= 1;
        g[i][c - 1] |= 4;
    }
    for (int i = 0; i < c; i++)
    {
        g[0][i] |= 2;
        g[r - 1][i] |= 8;
    }
}
void add_wall(int x1, int y1, int x2, int y2)
{
    if (x1 < x2)
    {
        g[y1][x1] |= 4;
        g[y2][x2] |= 1;
    }
    else if (x1 > x2)
    {
        g[y1][x1] |= 1;
        g[y2][x2] |= 4;
    }
    else if (y1 < y2)
    {
        g[y1][x1] |= 8;
        g[y2][x2] |= 2;
    }
    else
    {
        g[y1][x1] |= 2;
        g[y2][x2] |= 8;
    }
}
void find_end()
{
    int curx =0, cury = 0;
    myset.insert(make_pair(0, 0));
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'L') curx--;
        else if (s[i] == 'R') curx++;
        else if (s[i] == 'U') cury++;
        else cury--;
        myset.insert(make_pair(curx, cury));
    }
    endx = curx;
    endy = cury;
}
void bfs(int gg[105][105], int sx, int sy)
{
    memset(vis, 0, sizeof(vis));
    queue< pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(sx, sy), 0));
    gg[sy][sx] = 0;
    vis[sy][sx] = true;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int layer = q.front().second;
        q.pop();
        if ((g[y][x] & 1) == 0 && !vis[y][x - 1])
        {
            q.push(make_pair(make_pair(x - 1, y), layer + 1));
            gg[y][x - 1] = layer + 1;
            vis[y][x - 1] = true;
        }
        if ((g[y][x] & 2) == 0 && !vis[y - 1][x])
        {
            q.push(make_pair(make_pair(x, y - 1), layer + 1));
            gg[y - 1][x] = layer + 1;
            vis[y - 1][x] = true;
        }
        if ((g[y][x] & 4) == 0 && !vis[y][x + 1])
        {
            q.push(make_pair(make_pair(x + 1, y), layer + 1));
            gg[y][x + 1] = layer + 1;
            vis[y][x + 1] = true;
        }
        if ((g[y][x] & 8) == 0 && !vis[y + 1][x])
        {
            q.push(make_pair(make_pair(x, y + 1), layer + 1));
            gg[y + 1][x] = layer + 1;
            vis[y + 1][x] = true;
        }
    }
}
bool path(int y, int x)
{
    return myset.find(make_pair(x, y)) != myset.end();
}
void print(int gg[105][105])
{
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = 0; j < c; j++) cout << gg[i][j] << ' ';
        cout << endl;
    }
}
int main()
{
    int t, n;
    bool flag;
    scanf("%d", &t);
    while(t--)
    {
        flag = true;
        memset(g1, 5, sizeof(g1));
        memset(g2, 5, sizeof(g2));
        myset.clear();
        scanf("%d%d%s%d", &c, &r, s, &n);
        init_g();
        len = strlen(s);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
            add_wall(x1[i], y1[i], x2[i], y2[i]);
        }
        find_end();
        bfs(g1, 0, 0);
        bfs(g2, endx, endy);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (!path(i, j) && g1[i][j] + g2[i][j] <= len)
                {
                    flag = false;
                    goto answer;
                }
        for (int i = 0; i < n; i++)
        {
            if (g1[y1[i]][x1[i]] + g2[y2[i]][x2[i]] >= len && g1[y2[i]][x2[i]] + g2[y1[i]][x1[i]] >= len)
            {
                flag = false;
                break;
            }
        }
        answer:
        if (flag) puts("CORRECT");
        else puts("INCORRECT");
    }
    return 0;
}
