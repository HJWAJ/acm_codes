/*
ID: hjw00002
PROG: money
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
long long int val[30];
long long int dp[10100];
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int num,n,i,j;
    scanf("%d%d",&num,&n);
    for(i=0;i<num;i++)scanf("%lld",val+i);
    dp[0]=1;
    for(i=0;i<num;i++)
        for(j=val[i];j<=n;j++)
            dp[j]+=dp[j-val[i]];
    printf("%lld\n",dp[n]);
    return 0;
}
