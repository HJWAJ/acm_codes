#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

const int inf = 0x3f3f3f3f;

int cost[505][505];
int cnt[505], path[505], lowcost[505], num, sum;
bool vis[505];

void dij(int n, int start)
{
    memset(vis, 0, sizeof(vis));
    vis[start] = true;
    for(int i=0;i<n;i++)
    {
        lowcost[i] = cost[start][i];
        path[i] = start;
    }
    path[start] = -1;
    int pre = start;
    for(int i=1;i<n;i++)
    {
        int min = inf;
        for(int j=0;j<n;j++)
            if(!vis[j] && lowcost[pre]+cost[pre][j]<lowcost[j])
            {
                lowcost[j] = lowcost[pre] + cost[pre][j];
                path[j] = pre;
            }
        for(int j=0;j<n;j++)
            if(!vis[j] && lowcost[j]<min)
            {
                min = lowcost[j];
                pre = j;
            }
        vis[pre] = true;
    }
}

void dfs(int n, int start, int end, int nowdis, int nowcnt)
{
    if(nowdis > lowcost[end]) return;
    if(start == end)
    {
        num++;
        if(nowcnt > sum) sum = nowcnt;
        return;
    }
    vis[start] = 1;
    for(int i=0;i<n;i++)
        if(!vis[i] && i!=start && cost[start][i]!=inf)
        {
            dfs(n, i, end, nowdis+cost[start][i], nowcnt+cnt[i]);
            vis[i] = 0;
        }
}

int main()
{
    int m,n,st,ed,val,c1,c2;
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i=0;i<n;i++) scanf("%d", cnt+i);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) cost[i][j] = 0;
            else cost[i][j] = inf;
        }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d", &st, &ed, &val);
        if(cost[st][ed] > val) cost[st][ed] = cost[ed][st] = val;
    }
    if(c1==c2) printf("1 %d\n", cnt[c1]);
    else
    {
        dij(n, c1);
        //cout<<lowcost[c2]<<endl;
        num = sum = 0;
        memset(vis, 0, sizeof(vis));
        dfs(n, c1, c2, 0, cnt[c1]);
        printf("%d %d\n", num, sum);
    }
    return 0;
}
