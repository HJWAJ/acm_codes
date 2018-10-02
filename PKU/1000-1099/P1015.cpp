#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<map>
using namespace std;
int dp[25][805],path[25][805],p[205],d[205],pt[25];
int N,M;
int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int vis(int i,int j,int k)
{
    while(i>0 && path[i][j]!=k)
    {
        j-=p[path[i][j]]-d[path[i][j]];
        i--;
    }
    return i;
}
void DP()
{
    int i,j,k,m=20*M,n=2*m,v,w;
    memset(dp,-1,sizeof(dp));
    for(dp[0][m]=i=0;i<M;i++)
        for(j=0;j<=n;j++)
            if(dp[i][j]>=0)
                for(k=1;k<=N;k++)
                {
                    v=p[k]-d[k];
                    w=p[k]+d[k];
                    if(dp[i+1][j+v]<dp[i][j]+w)
                        if(!vis(i,j,k))
                        {
                            dp[i+1][j+v]=dp[i][j]+w;
                            path[i+1][j+v]=k;
                        }
                }
}
int find_max()
{
    int k=20*M,j;
    for(j=0;dp[M][k+j]<0 && dp[M][k-j]<0;j++);
    return dp[M][k+j]>dp[M][k-j]?k+j:k-j;
}
void print_path(int k)
{
    int i;
    for(i=M;i>=1;i--)
    {
        pt[i]=path[i][k];
        k-=p[path[i][k]]-d[path[i][k]];
    }
    qsort(pt+1,M,sizeof(int),cmp);
    for(i=1;i<M;i++)printf("%d ",pt[i]);
    printf("%d\n",pt[M]);
}
void deal(int t)
{
    int k;
    DP();
    k=find_max();
    printf("Jury #%d\n",t);
    printf("Best jury has value %d for prosecution and value %d for defence:\n",(dp[M][k]+k-20*M)/2,(dp[M][k]-k+20*M)/2);
    print_path(k);
    puts("");
}
int main()
{
    int tt=0;
    while(scanf("%d%d",&N,&M) && (N||M))
    {
        tt++;
        for(int i=1;i<=N;i++)scanf("%d%d",p+i,d+i);
        deal(tt);
    }
    return 0;
}
