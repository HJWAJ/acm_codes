#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
bool dp[100005];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int n,a[15],i,j,d;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%d",a+i);
        if(n==1)
        {
            puts("0");
            continue;
        }
        for(i=0;i<n;i++)
            if(a[i]==1)
            {
                puts("0");
                break;
            }
        if(i<n)continue;
        d=gcd(a[0],a[1]);
        for(i=2;i<n;i++)d=gcd(d,a[i]);
        if(d!=1)
        {
            puts("0");
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=1;i<=100000;i++)
            for(j=0;j<n;j++)
                if(i>=a[j] && dp[i-a[j]])
                    dp[i]=1;
        for(i=100000;i>=1;i--)
            if(!dp[i])
            {
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
