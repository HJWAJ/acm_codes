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
using namespace std;
int a[105][105],len[105],sum[105][105];
int dp[105][105];
int ans[105][10005];
int main()
{
    int n,m,i,j,k,tmp;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",len+i);
        sum[i][0]=0;
        for(j=0;j<len[i];j++)
        {
            scanf("%d",&a[i][j]);
            sum[i][j+1]=sum[i][j]+a[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
        for(j=1;j<=len[i];j++)
            for(k=0;k<=j;k++)
            {
                tmp=sum[i][k]+sum[i][len[i]]-sum[i][len[i]-j+k];
                if(tmp>dp[i][j])dp[i][j]=tmp;
            }
    memset(ans,0,sizeof(ans));
    for(i=0;i<n;i++)
        for(j=0;j<=m;j++)
            for(k=0;k<=len[i]&&j+k<=m;k++)
                if(ans[i+1][j+k]<ans[i][j]+dp[i][k])
                    ans[i+1][j+k]=ans[i][j]+dp[i][k];
    for(j=1;j<=m;j++)
        if(ans[n][j]>ans[n][0])
            ans[n][0]=ans[n][j];
    printf("%d\n",ans[n][0]);
    return 0;
}
