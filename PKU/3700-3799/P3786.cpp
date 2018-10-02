#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[1005][1005][2];

int main()
{
    int i,j,t,tt,n,k;
    memset(dp,0,sizeof(dp));
    dp[1][0][0]=dp[1][0][1]=1;
    for(i=2;i<=1000;i++)
    {
        dp[i][0][1]=dp[i-1][0][0];
        dp[i][0][0]=dp[i-1][0][0]+dp[i-1][0][1];
        for(j=1;j<i;j++)
        {
            dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
            dp[i][j][1]=dp[i-1][j][0]+dp[i-1][j-1][1];
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&tt,&n,&k);
        printf("%d %d\n",tt,dp[n][k][0]+dp[n][k][1]);          
    }
    
    //system("pause");
    return 0;
}
