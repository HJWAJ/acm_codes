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
const int mod=1000000007;
int dp[10000005][4];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(i=1;i<4;i++)dp[1][i]=1;
    for(i=2;i<=n;i++)
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                if(j!=k)
                {
                    dp[i][j]+=dp[i-1][k];
                    dp[i][j]%=mod;
                }
    printf("%d",dp[n][0]);
    return 0;
}
