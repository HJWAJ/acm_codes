/*
ID: hjw00002
PROG: comehome
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
int a[64][64];
char st[2],ed[2];
int dist[64],vis[64],path[64];
bool iscap(char ch)
{
    return ch>='A' && ch<='Z';
}
void dij(int beg)
{
    int i,j,min,n=52;
    memset(vis,0,sizeof(vis));
    vis[beg]=1;
    for(i=0; i<n; i++)
    {
        dist[i]=a[beg][i];
        path[i]=beg;
    }
    dist[beg]=0;
    path[beg]=-1;
    int pre=beg;
    for(i=1; i<n; i++)
    {
        min=inf;
        for(j=0; j<n; j++)
            if(!vis[j] && dist[pre]+a[pre][j]<dist[j])
            {
                dist[j]=dist[pre]+a[pre][j];
                path[j]=pre;
            }
        for(j=0; j<n; j++)
            if(!vis[j] && dist[j]<min)
            {
                min=dist[j];
                pre=j;
            }
        vis[pre]=1;
    }
}
int main()
{
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    int n,tmp,start,end,mmin=inf,mindis,i,j;
    scanf("%d",&n);
    for(i=0; i<64; i++)
        for(j=0; j<64; j++)
        {
            if(i!=j)a[i][j]=inf;
            else a[i][j]=0;
        }
    while(n--)
    {
        scanf("%s%s%d",st,ed,&tmp);
        if(iscap(st[0]))start=st[0]-'A';
        else start=st[0]-'a'+26;
        if(iscap(ed[0]))end=ed[0]-'A';
        else end=ed[0]-'a'+26;
        if(end!=start && a[end][start]>tmp)
        {
            a[end][start]=tmp;
            a[start][end]=tmp;
        }
    }
    dij(25);
    for(i=0; i<25; i++)
        if(dist[i]<mmin)
        {
            mmin=dist[i];
            mindis=i;
        }
    printf("%c %d\n",mindis+'A',mmin);
    return 0;
}
