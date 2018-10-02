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
    int x, y;
};

const int maxn=305;
Point bob[maxn], dog[maxn];
bool graph[maxn][maxn];
bool yUsed[maxn];
int  yMatch[maxn], xMatch[maxn];
int  nx, ny;

int dfs(int p)
{
	int i;
	for(i=0; i<ny; i++)
		if( graph[p][i] && !yUsed[i])//p与i有边相连，且i还没有被匹配
		{
			yUsed[i]=true;
			if( yMatch[i]<0 || dfs(yMatch[i]))
			{
				yMatch[i]=p;
				xMatch[p]=i;
				return 1;
			}
		}
	return 0;
}

int maxMatch()
{
	int i, ans=0;
	memset(yMatch, -1, sizeof(yMatch));
	memset(xMatch, -1, sizeof(xMatch));
	for(i=0; i<nx; i++)
	{
		memset(yUsed, false, sizeof(yUsed));
		ans+=dfs(i);
	}
	return ans;
}
double dis(Point a, Point b)
{
    return sqrt(((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) * 1.0);
}
int main()
{
    while (scanf("%d%d", &nx, &ny) != EOF)
    {
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < nx; i++) scanf("%d%d", &bob[i].x, &bob[i].y);
        for (int i = 0; i < ny; i++) scanf("%d%d", &dog[i].x, &dog[i].y);
        for (int i = 0; i < nx - 1; i++)
            for (int j = 0; j < ny; j++)
                if (dis(bob[i], dog[j]) + dis(bob[i + 1], dog[j]) <= 2 * dis(bob[i], bob[i + 1]))
                    graph[i][j] = 1;
        printf("%d\n", maxMatch() + nx);
        printf("%d %d", bob[0].x, bob[0].y);
        for (int i = 1; i < nx; i++)
        {
            if (xMatch[i - 1] != -1) printf(" %d %d", dog[xMatch[i - 1]].x, dog[xMatch[i - 1]].y);
            printf(" %d %d", bob[i].x, bob[i].y);
        }
        puts("");
    }
    return 0;
}
