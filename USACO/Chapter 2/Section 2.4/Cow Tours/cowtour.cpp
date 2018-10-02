/*
ID: hjw00002
PROG: cowtour
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
const double inf=1e10;
char s[155][155];
double dis[155][155];
double maxdis[155];
double x[155],y[155];
bool vis[155][155];
double dist(int a,int b)
{
    return sqrt( (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]) );
}
void floyd(int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
       for(i=0;i<n;i++)
           for(j=0;j<n;j++)
               dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
void maxdist(int n)
{
    int i,j;
    memset(maxdis,0,sizeof(maxdis));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(dis[i][j]>maxdis[i] && dis[i][j]<inf)
                maxdis[i]=dis[i][j];
}
void dfs(int a,int n,int now)
{
    int i;
    vis[now][a]=1;
    for(i=0;i<n;i++)
        if(s[a][i]=='1' && !vis[now][i])
            dfs(i,n,now);
}
void ok(int n)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)dfs(i,n,i);
}
int main()
{
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	int n,i,j;
	double mmax=0,tmp,mmin=inf;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%lf%lf",x+i,y+i);
	for(i=0;i<n;i++)scanf("%s",s[i]);
	for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(i==j)dis[i][j]=0;
            else if(s[i][j]=='1')dis[i][j]=dist(i,j);
            else dis[i][j]=inf;
        }
    ok(n);
    floyd(n);
    maxdist(n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(dis[i][j]<inf && dis[i][j]>mmax)
                mmax=dis[i][j];
    //printf("%.6lf\n",mmax);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i!=j && !vis[i][j])
            {
                tmp=dist(i,j)+maxdis[i]+maxdis[j];
                if(tmp<mmin)mmin=tmp;
            }
    if(mmax>mmin)mmin=mmax;
    printf("%.6lf\n",mmin);
	return 0;
}
