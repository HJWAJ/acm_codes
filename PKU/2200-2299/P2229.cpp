#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[1000005];
const int mod=1000000000;

int main()
{
    int i,n;
    dp[1]=1;dp[2]=2;
    for(i=3;i<1000001;i++)
    {
        if(i&1)dp[i]=dp[i-1];
        else dp[i]=(dp[i-2]+dp[i/2])%mod;
    }
    while(scanf("%d",&n)!=EOF)printf("%d\n",dp[n]);
    
    return 0;
}
