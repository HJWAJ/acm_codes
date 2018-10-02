#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
struct node
{
    int x,y;
    bool equals(node a)
    {
        if(x==a.x && y==a.y)return 1;
        return 0;
    }
};
int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,1},{2,-1}};
int n;
int a[305][305];
bool ok(node d)
{
    if(d.x<0 || d.x>=n)return 0;
    if(d.y<0 || d.y>=n)return 0;
    if(a[d.x][d.y]!=-1)return 0;
    return 1;
}
int bfs(node s,node t)
{
    queue<node> q;
    node tmp,tmp1;
    int i;
    q.push(s);
    a[s.x][s.y]=0;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp.equals(t))return a[t.x][t.y];
        else
        {
            for(i=0;i<8;i++)
            {
                tmp1=tmp;
                tmp1.x+=dir[i][0];
                tmp1.y+=dir[i][1];
                if(ok(tmp1))
                {
                    a[tmp1.x][tmp1.y]=a[tmp.x][tmp.y]+1;
                    q.push(tmp1);
                }
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    node start,end;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d%d%d%d",&start.x,&start.y,&end.x,&end.y);
        memset(a,-1,sizeof(a));
        printf("%d\n",bfs(start,end));
    }
    return 0;
}
