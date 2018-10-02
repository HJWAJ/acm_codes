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
int a[505][505];
vector<int> ans;
int main()
{
    int n, x, y, dir;
    while (scanf("%d", &n) != EOF)
    {
        ans.clear();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        x = y = dir = 0;
        while (x < n - 1 || y < n - 1)
        {
            ans.push_back(a[x][y]);
            if (dir == 0)
            {
                x--;
                y++;
                if (x < 0 && y == n)
                {
                    x += 2;
                    y --;
                    dir ^= 1;
                }
                else if (x < 0)
                {
                    x = 0;
                    dir ^= 1;
                }
                else if (y == n)
                {
                    y--;
                    x += 2;
                    dir ^= 1;
                }
            }
            else
            {
                x++;
                y--;
                if (x == n && y < 0)
                {
                    x--;
                    y += 2;
                    dir ^= 1;
                }
                else if (x == n)
                {
                    x--;
                    y += 2;
                    dir ^= 1;
                }
                else if (y < 0)
                {
                    y++;
                    dir ^= 1;
                }
            }
        }
        for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
        printf("%d \n", a[n - 1][n - 1]);
    }
    return 0;
}
