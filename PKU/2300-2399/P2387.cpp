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
const int inf=9999999;
int g[2005][2005];
int dis[2005],bo[2005];
void dij(int st,int n)
{
    int i,j,min,pre=st;
    memset(bo,0,sizeof(bo));
    bo[st]=1;
    for(i=0;i<n;i++)dis[i]=g[st][i];
    dis[st]=0;
    for(i=1;i<n;i++)
    {
        min=inf;
        for(j=0;j<n;j++)
            if(!bo[j] && dis[pre]+g[pre][j]<dis[j])
                dis[j]=dis[pre]+g[pre][j];
        for(j=0;j<n;j++)
            if(!bo[j] && dis[j]<min)
            {
                min=dis[j];
                pre=j;
            }
        bo[pre]=1;
    }
}
void init(int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(i==j)g[i][j]=0;
            else g[i][j]=inf;
        }
}
int main()
{
    int s,t,n,m,v,i;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        init(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&s,&t,&v);
            if(v<g[s-1][t-1])g[s-1][t-1]=g[t-1][s-1]=v;
        }
        dij(0,n);
        printf("%d\n",dis[n-1]);
    }
    return 0;
}
