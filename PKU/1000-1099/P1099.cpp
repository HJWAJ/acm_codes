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
using namespace std;
int a[15][15];
char s[105][105];
bool used(int x, int y, int width, int height)
{
    if (x < 0 || y < 0) return true;
    if (x > width || y > height) return true;
    if (s[y - 1][x] == '|' || s[y + 1][x] == '|' || s[y][x - 1] == '-' || s[y][x + 1] == '-') return true;
    return false;
}
void print(int n, int t)
{
    printf("Case %d:\n", t);
    puts("");
    int height = 4 * (n - 1) + 3;
    for (int i = 0; i < height; i++)
        puts(s[i]);
    puts("");
}
void work(int n)
{
    int width = 4 * n + 3;
    int height = 4 * (n - 1) + 3;
    // draw board
    for (int i = 0; i < height; i++) s[i][width] = '\0';
    for (int i = 0; i < height; i++) s[i][0] = s[i][width - 1] = '*';
    for (int i = 0; i < width; i++) s[0][i] = s[height - 1][i] = '*';

    // draw O
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            s[4 * i + 1][4 * j + 3] = 'O';

    // draw H
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            s[4 * i + 1][4 * j + 1] = 'H';
            if (i < n - 1) s[4 * i + 3][4 * j + 3] = 'H';
            if (j == n - 1) s[4 * i + 1][4 * j + 5] = 'H';
        }
    // draw space
    for (int i = 1; i < height - 1; i++)
        for (int j = 1; j < width - 1; j++)
            if (s[i][j] != 'H' && s[i][j] != 'O')
                s[i][j] = ' ';
    // draw key
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1) s[4 * i + 1][4 * j + 2] = s[4 * i + 1][4 * j + 4] = '-';
            else if (a[i][j] == -1) s[4 * i][4 * j + 3] = s[4 * i + 2][4 * j + 3] = '|';
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0)
            {
                int lx, ly, rx, ry, ux, uy, bx, by;
                lx = 4 * j + 1;
                ly = 4 * i + 1;
                rx = 4 * j + 5;
                ry = 4 * i + 1;
                ux = 4 * j + 3;
                uy = 4 * i - 1;
                bx = 4 * j + 3;
                by = 4 * i + 3;
                if (!used(lx, ly, width, height)) s[ly][lx + 1] = '-';
                else s[ry][rx - 1] = '-';
                if (!used(ux, uy, width, height)) s[uy + 1][ux] = '|';
                else s[by - 1][bx] = '|';
            }
}
int main()
{
    int n, tt = 0;
    while (scanf("%d", &n) && n)
    {
        tt++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        work(n);
        print(n, tt);
    }
    return 0;
}
