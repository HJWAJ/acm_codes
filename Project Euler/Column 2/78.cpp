#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int dp[100005];
const int mod=1000000;
int main()
{
    int i,j,x,y;
    memset(dp,0,sizeof(dp));
    dp[0]=dp[1]=1;
    for(i=2;;i++)
    {
        for(j=1;j<=i;j++)
        {
            x=i-j*(j*3-1)/2;
            y=i-j*(j*3+1)/2;
            if(x<0 && y<0)break;
            if(j&1)
            {
                if(x>=0)dp[i]=(dp[i]+dp[x])%mod;
                if(y>=0)dp[i]=(dp[i]+dp[y])%mod;
            }
            else
            {
                if(x>=0)dp[i]=(dp[i]-dp[x]+mod)%mod;
                if(y>=0)dp[i]=(dp[i]-dp[y]+mod)%mod;
            }
        }
        if(!dp[i])
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
