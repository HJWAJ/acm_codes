#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int inf=0x7fffffff;
int M,N,dmax,dmin,tmin;
int c[105][105],degree[105],dist[105];
bool s[105],use[105];

bool In(int a)
{
    return abs(dmax-a)<=M && abs(dmin-a)<=M;     
}

int dij()
{
    int i,j,k;
    for(i=0;i<=N;i++)
    {
        dist[i]=c[0][i];
        s[i]=0;                
    }    
    s[0]=use[0]=1;
    for(i=1;i<=N;i++)
    {
        tmin=inf;
        for(j=1;j<=N;j++)
        {
            if(!s[j] && use[j] && tmin>dist[j])
            {
                k=j;
                tmin=dist[j];         
            }              
        }                 
        s[k]=1;
        for(j=1;j<=N;j++)
        {
            if(!s[j] && use[j] && dist[k]<inf && c[k][j]<inf && dist[j]>dist[k]+c[k][j])dist[j]=dist[k]+c[k][j];                 
        }
    }
    return dist[1];
}

void solve()
{
    int i,j,m,an=inf,t;
    for(i=0;i<=N;i++)
    {
        m=degree[i];
        dmax=m;
        dmin=m-M;
        for(j=0;j<=N;j++)
        {
            if(In(degree[j]))use[j]=1;
            else use[j]=0;                 
        }                 
        t=dij();
        if(an>t)an=t;
    }     
    printf("%d\n",an);
}

int main()
{
    int i,j,k,m,n;
    while(scanf("%d%d",&M,&N)!=EOF)
    {
        for(i=0;i<=N;i++)
            for(j=0;j<=N;j++)
                c[i][j]=inf;
        
        for(i=1;i<=N;i++)
        {
            scanf("%d%d%d",&c[0][i],&degree[i],&k);
            for(j=1;j<=k;j++)
            {
                scanf("%d%d",&m,&n);
                c[m][i]=n;                 
            }                 
        }                 
        degree[0]=degree[1];
        dmax=dmin=degree[0];
        solve();              
    }
    
    return 0;
}
