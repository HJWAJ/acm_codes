/*
ID: hjw00002
PROG: nocows
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int mod=9901;
int dp[205][105];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    int i,j,k,kk,n,h;
    scanf("%d%d",&n,&h);
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(i=3;i<200;i+=2)
        for(j=1;j<=i;j+=2)
            for(k=1;k<=(j+1)/2;k++)
                for(kk=1;kk<=(i-j)/2;kk++)
                {
                    dp[i][max(k,kk)+1]+=dp[j][k]*dp[i-j-1][kk];
                    dp[i][max(k,kk)+1]%=mod;
                }
    printf("%d\n",dp[n][h]);
    return 0;
}
