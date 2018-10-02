/*
ID: hjw00002
PROG: humble
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int prime[105],flag[105],tmp[105],dp[100005];
int min(int a[],int n)
{
    int res=a[0],i;
    for(i=1;i<n;i++)
        if(res>a[i])
            res=a[i];
    return res;
}
int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    int n,i,m,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",prime+i);
    dp[1]=1;
    for(i=0;i<n;i++)flag[i]=1;
    for(i=2;i<=m+1;i++)
    {
        for(j=0;j<n;j++)tmp[j]=prime[j]*dp[flag[j]];
        dp[i]=min(tmp,n);
        for(j=0;j<n;j++)
            if(dp[i]==dp[flag[j]]*prime[j])
                flag[j]++;
    }
    printf("%d\n",dp[m+1]);
    return 0;
}
