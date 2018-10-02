#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
struct Node
{
    long long x, y;
    int add;
} node[205];
long long d[205];
struct Vis
{
    int id, pass, add;
    Vis(int id, int pass, int add)
    {
        this->id = id;
        this->pass = pass;
        this->add = add;
    }
};
int cmp(Node n1, Node n2, long long r)
{
    long long dist = (n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y);
    if (dist < r * r) return -1;
    if (dist == r * r) return 0;
    return 1;
}
int bfs(int n, int m, int k, long long r)
{
    memset(d, 0x5A, sizeof(d));
    d[0] = 0;
    queue<Vis> q;
    q.push(Vis(0, 0, 0));
    while (!q.empty())
    {
        Vis cur = q.front();
        q.pop();
        for (int i = 1; i < n + m; i++)
            if (i != cur.id && cmp(node[i], node[cur.id], r) <= 0 && cur.add + node[i].add <= k && d[i] > cur.pass + 1)
            {
                d[i] = cur.pass + 1;
                q.push(Vis(i, d[i], cur.add + node[i].add));
            }
    }
    return d[1] - 1;
}
int main()
{
    int n, m, k;
    long long r;
    while (scanf("%d%d%d%lld", &n, &m, &k, &r) != EOF)
    {
        for (int i = 0; i < n + m; i++)
        {
            scanf("%lld%lld", &node[i].x, &node[i].y);
            node[i].add = (i >= n ? 1 : 0);
        }
        printf("%d\n", bfs(n, m, k, r));
    }
    return 0;
}
