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
bool b[105][105];
void draw(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++)
            b[i][j] = true;
}
int main()
{
    int n, x1, y1, x2, y2, cnt;
    while (scanf("%d", &n) != EOF)
    {
        cnt = 0;
        memset(b, 0, sizeof(b));
        while (n--)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            draw(x1, y1, x2, y2);
        }
        for (int i = 0; i <= 100; i++)
            for (int j = 0; j <= 100; j++)
                if (b[i][j])
                    cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
