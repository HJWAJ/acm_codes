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
int dp[105][105];//i瓶放j花的最大价值
int a[105][105];
const int inf=-(1<<20);
int main()
{
    int n,m,i,j,max;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        for(j=1;j<=m;j++)
            for(i=1;i<=j;i++)
            {
                dp[j][i]=inf;
                if(j>i)dp[j][i]=dp[j-1][i];
                if(dp[j-1][i-1]+a[i-1][j-1]>dp[j][i])dp[j][i]=dp[j-1][i-1]+a[i-1][j-1];
            }
        max=inf;
        for(i=n;i<=m;i++)
            if(max<dp[i][n])
                max=dp[i][n];
        printf("%d\n",max);
    }
    return 0;
}
