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
struct Point
{
    double x, y;
} pnt[2][105];
double line_k(Point a, Point b)
{
    return (b.y - a.y) / (b.x - a.x);
}
int main()
{
    int n, max_index;
    double max_x;
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &pnt[0][i].x, &pnt[0][i].y);
            pnt[1][i].x = pnt[0][i].x;
            pnt[1][i].y = pnt[0][i].y - 1;
        }
        max_index = 1;
        max_x = pnt[0][1].x;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = 0; k < 2; k++)
                {
                    double kk = line_k(pnt[k][i], pnt[1 - k][j]);
                    int index, l;
                    double y;
                    for (l = 0, index = -1; l < n; l++)
                    {
                        if (l == i) y = pnt[k][i].y;
                        else if (l == j) y = pnt[1 - k][j].y;
                        else y = pnt[k][i].y + kk * (pnt[0][l].x - pnt[k][i].x);

                        if (y > pnt[0][l].y || y < pnt[1][l].y)
                        {
                            index = l - 1;
                            break;
                        }
                    }
                    if (l == n)
                    {
                        puts("Through all the pipe.");
                        goto end;
                    }
                    if (index >= max_index)
                    {
                        max_index = index;
                        double offset = y > pnt[0][index + 1].y ? 0 : -1;
                        double kkk = line_k(pnt[0][index], pnt[0][index + 1]);
                        double x = (pnt[0][index].y + offset - pnt[k][i].y + kk * pnt[k][i].x - kkk * pnt[0][index].x) / (kk - kkk);
                        if (x > max_x) max_x = x;
                    }
                }
        if (max_index == n - 1) puts("Through all the pipe.");
        else printf("%.2lf\n", max_x);
        end:;
    }
    return 0;
}
