#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int c[205],w[205],dp[1005];
int max(int a,int b,int c)
{
    return max(max(a,b),c);
}
int main()
{
    int n,m,g,i,j,t,wei,id;
    while(scanf("%d%d%d",&n,&m,&g)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(c,0,sizeof(c));
        memset(w,0,sizeof(w));
        for(i=1;i<=n;i++)scanf("%d%d",c+i,w+i);
        for(i=n+1;i<=n+m;i++)
        {
            scanf("%d",&t);
            while(t--)
            {
                scanf("%d",&id);
                c[i]+=c[id];
                w[i]+=w[id];
            }
            scanf("%d",&wei);
            w[i]+=wei;
        }
        for(j=1;j<=g;j++)
            for(i=1;i<=n+m;i++)
            {
                if(j>=c[i])dp[j]=max(dp[j-c[i]]+w[i],dp[j-1],dp[j]);
                else dp[j]=max(dp[j-1],dp[j]);
            }
        printf("%d\n",dp[g]);
    }
    return 0;
}
